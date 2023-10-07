#include "PrecompiledHeaders.h"
#include "Proto/Application.h"
#include "WindowsInputHub.h"
#include "GLFW/glfw3.h"
namespace Proto{
	bool WindowsInputHub::isPressedFunction(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT; 
	};
	
}