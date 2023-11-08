#include "PrecompiledHeaders.h"
#include "openGLRenderer.h"
#include "glad/glad.h"

namespace Proto {
	void openGLRenderer::Draw(VertexArrayAbstraction& v_Array, uint32_t vertecies, float lineWidth)
	{
		return;
	}
	void openGLRenderer::ClearWindow() {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void openGLRenderer::Begin()
	{
		return;
	}
	void openGLRenderer::End()
	{
		return;
	}
	void openGLRenderer::Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		return; 
	}
}