#include "PrecompiledHeaders.h"
#include <GLFW/glfw3.h>
#include "Time.h"

namespace Proto {
	float Time::getFrameTime() {
		return (float)glfwGetTime();
	}

	void Time::CalculateFrameTime(float pastTime, float frameTime){
		float time = getFrameTime();
		frameTime = time - pastTime;
		pastTime = time; 
	}
}