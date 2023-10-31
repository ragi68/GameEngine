#include "Proto/EntryCore.h"
#include "PrecompiledHeaders.h"
#include "openglcontext.h"

namespace Proto {
	openglcontext::openglcontext(GLFWwindow* window) : window(window) {}; //inits glfw window for context

	void openglcontext::Init() {
		glfwMakeContextCurrent(window);
		int loader = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//PROTO_CORE_LOG(loader, "GLAD Init Failed."); 
	}

	void openglcontext::SwapBuffer() {
		glfwSwapBuffers(window);
	}
}