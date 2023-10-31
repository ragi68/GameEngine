#pragma once

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "RenderAPI/rendercontext.h"


namespace Proto{
	class openglcontext : public rendercontext
	{
	public:
		openglcontext(GLFWwindow* window); 
		virtual void Init() override;
		virtual void SwapBuffer() override;

	public:
		GLFWwindow* window; 
	};
}

