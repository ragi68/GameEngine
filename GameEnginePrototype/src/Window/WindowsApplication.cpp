#include "PrecompiledHeaders.h"
#include "WindowsApplication.h"
#include "Proto/logging.h"

namespace Proto {
	static bool windowInit = false;

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

			windowInit = true;
		}

		window = glfwCreateWindow((int)size.width, (int)size.height, "Proto Engine", nullptr, nullptr); //create window with nullptr return
		glfwMakeContextCurrent(window); //makes OpenGL context of window on current calling thread, meaing only one thread of executables every time a window is open. 
		glfwSetWindowUserPointer(window, &windowData);
		VSync(true);
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

	}

}


