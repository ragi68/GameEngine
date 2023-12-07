#pragma once
#include "RenderAPI/RenderAbstraction.h"

namespace Proto{
	class openGLRenderer : public RenderAbstraction {
		virtual void DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, glm::mat4& transform, std::shared_ptr<ShaderAbstraction> shader) override;
		virtual void ClearWindow() override;

	};
}