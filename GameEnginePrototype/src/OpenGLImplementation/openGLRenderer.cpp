#include "PrecompiledHeaders.h"
#include "openGLRenderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Proto {
	void openGLRenderer::DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, glm::mat4& transform, std::shared_ptr<ShaderAbstraction> shader, Camera3D camera)
	{
		shader->Bind();
		shader->BindMatrixData("v_matrix", camera.GetVPMatrix());
		shader->BindMatrixData("transform", transform);
		v_Array->Bind(); 
		glDrawElements(GL_TRIANGLES, v_Array->GetIndexBuffer()->GetSize(), GL_UNSIGNED_INT, nullptr); //note to abstract this entire thing out to a separate script(maybe depending on mood lmao) and find way to save camera before hand

		
	}
	void openGLRenderer::ClearWindow() {
		glClear(GL_COLOR_BUFFER_BIT);
	}



}