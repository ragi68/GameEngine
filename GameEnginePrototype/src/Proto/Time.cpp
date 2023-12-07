#include "PrecompiledHeaders.h"
#include <GLFW/glfw3.h>
#include "Time.h"

namespace Proto {
	float Time::getFrameTime() {
		return (float)glfwGetTime();
	}

	
}

