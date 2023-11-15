#include "PrecompiledHeaders.h"
#include "openGLRenderer.h"
#include "glad/glad.h"

namespace Proto {
	void openGLRenderer::DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, float lineWidth)
	{
		//glLineWidth(lineWidth);
		glDrawElements(GL_TRIANGLES, v_Array->GetIndexBuffer()->GetSize(), GL_UNSIGNED_INT, nullptr);
		
	}
	void openGLRenderer::ClearWindow() {
		glClear(GL_COLOR_BUFFER_BIT);
	}



}