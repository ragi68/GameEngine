#include "PrecompiledHeaders.h"
#include "WindowsApplication.h"
#include "Proto/logging.h"
#include "Proto/EventSystem/Keys.h"
#include "Proto/EventSystem/MouseEvent.h"
#include "Proto/EventSystem/AppEvent.h"
#include "glad/glad.h"


namespace Proto {
	static bool windowInit = false;

	void GLFWErrorFun(int errCode, const char* desc) {
		PROTO_ERROR_MODULE("Error Code {0}. {1}", errCode, desc);
	}

	AbstractWin* AbstractWin::windowGenerator(const WindowSize& size) {
		return new WindowsApplication(size);
	}

	WindowsApplication::WindowsApplication(const WindowSize& size) {
		Init(size);
	}

	WindowsApplication::~WindowsApplication() {
		Destroy();
	}

	void WindowsApplication::Init(const WindowSize& size) {
		windowData.Width = size.width;
		windowData.Height = size.height;

		PROTO_INFO_MODULE("Window: {0}, {1}", windowData.Width, windowData.Height);
		if (!windowInit) {
			int done = glfwInit();
			PROTO_CORE_LOG(done, "Setup failed");
			glfwSetErrorCallback(GLFWErrorFun);
			windowInit = true;
		}

		window = glfwCreateWindow((int)size.width, (int)size.height, "Proto Engine", nullptr, nullptr); //create window with nullptr return
		glfwMakeContextCurrent(window);                                                                                     //makes OpenGL context of window on current calling thread, meaing only one thread of executables every time a window is open. 
		int loader = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PROTO_CORE_LOG(status, "GLAD Init Failed.")
		glfwSetWindowUserPointer(window, &windowData);
		VSync(true);

		//set callbacks
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height){
			Data& windowData = *(Data*)glfwGetWindowUserPointer(window); //sets a Data struct to have same reference (mem address) as the user window
			windowData.Width = width; //this and next gets new window hight and length
			windowData.Height = height;
			WindowResize event(width, height); //creates windoeResize event
			windowData.CallBack(event); //-> sets eventcallback variable to the event created previous line
		});
		//the lambda inside { []() } is of type GLFWwindowsizefun type (void)

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window){
			Data& windowData = *(Data*)glfwGetWindowUserPointer(window);
			CloseWindow e;
			windowData.CallBack(e);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			Data& windowData = *(Data*)glfwGetWindowUserPointer(window);
			switch (action) { //sees action(0, 1) and then sees cases. If the action is equal to the case, then is executes that case. 
				case GLFW_PRESS:
				{
					KeyPressed pressed(key, 0);
					windowData.CallBack(pressed);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyRelease release(key);
					windowData.CallBack(release);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressed pressed(key, 1);
					windowData.CallBack(pressed);
					break;
				}
	

			}

		}); 

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			Data& windowData = *(Data*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS: {
					MouseDown mousedown(mods);
					windowData.CallBack(mousedown);

					break;
				}
				case GLFW_RELEASE: {
					MouseUp mouserelease(mods);
					windowData.CallBack(mouserelease);

					break;
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double x_offset, double y_offset) {
			Data& windowData = *(Data*)glfwGetWindowUserPointer(window);
			MouseScroll scroll((float)x_offset, (float)y_offset);
			windowData.CallBack(scroll);

		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x_pos, double y_pos) {
			Data& windowData = *(Data*)glfwGetWindowUserPointer(window); //bro i need a macro for this shit
			MouseMoved moved((float)x_pos, (float)y_pos);
			windowData.CallBack(moved);

		});
	}

	void WindowsApplication::Destroy() {
		glfwDestroyWindow(window);
	}

	void WindowsApplication::VSync(bool enabled) {
		if (enabled) {
			//set update interval
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}
		windowData.vsync = enabled;

	}

	bool WindowsApplication::VSyncEnabled() const
	{
		return windowData.vsync;
	}

	void WindowsApplication::UpdateWindow() {
		glfwPollEvents(); //-> processes events and returns result immediately. 
		glfwSwapBuffers(window); //sets target of double-ended frame buffer to the window created 
		glClear(GL_COLOR_BUFFER_BIT);

	}

}


