#include "PrecompiledHeaders.h"
#include "Proto/Application.h"
#include "WindowsInputHub.h"
#include <GLFW/glfw3.h>
namespace Proto{
	InputHub* InputHub::input = new WindowsInputHub(); //creating singleton of input hub for windows - could leave all nllptr but since it is singleton, may as well
	bool WindowsInputHub::isPressedFunction(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;  
		// line 8 static casts the pointer we get(void*) into a 
		//GLFWwindow* type after getting going into the window instance, getting the pointer of the window, 
		//and then getting the pointer of the actual GLFW window. We then
		//get key from glfwgetkey and then compare to the macros to check for input. 
	};

	bool WindowsInputHub::isMousePressedFunction(int button) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS; 
		//retuirns if a key was pressed. 
	}

	std::pair<float, float> WindowsInputHub::CursorPosition() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		std::pair<double, double> cursorPos;
		glfwGetCursorPos(window, &std::get<0>(cursorPos), &std::get<0>(cursorPos));
		return { (float)std::get<0>(cursorPos), (float)std::get<1>(cursorPos) };
		//gives us the position of the cursor in the window
	}
}