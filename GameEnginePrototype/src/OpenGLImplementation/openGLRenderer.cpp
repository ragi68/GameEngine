#include "PrecompiledHeaders.h"
#include "openGLRenderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"-

namespace Proto {
	void openGLRenderer::DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, glm::mat4& transform, std::shared_ptr<ShaderAbstraction> shader)
	{
		shader->Bind();
		shader->BindMatrixData("transform", transform);
		glDrawElements(GL_TRIANGLES, v_Array->GetIndexBuffer()->GetSize(), GL_UNSIGNED_INT, nullptr);
		
	}
	void openGLRenderer::ClearWindow() {
		glClear(GL_COLOR_BUFFER_BIT);
	}



}