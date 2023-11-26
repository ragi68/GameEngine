#include "PrecompiledHeaders.h"
#include "Proto/InputModule.h"
#include "GLFW/glfw3.h"
#include "Proto/Application.h"

namespace Proto {
	bool InputModule::checkPressed(int key) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		int state = glfwGetKey(window, key);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
		// line 8 static casts the pointer we get(void*) into a 
		//GLFWwindow* type after getting going into the window instance, getting the pointer of the window, 
		//and then getting the pointer of the actual GLFW window. We then
		//get key from glfwgetkey and then compare to the macros to check for input. 
	}
	bool InputModule::checkMousePressed(int button) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> InputModule::GetCursorPosition() {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		std::pair<double, double> cursorPos;
		glfwGetCursorPos(window, &std::get<0>(cursorPos), &std::get<0>(cursorPos));
		return { (float)std::get<0>(cursorPos), (float)std::get<1>(cursorPos) };
	}
}

