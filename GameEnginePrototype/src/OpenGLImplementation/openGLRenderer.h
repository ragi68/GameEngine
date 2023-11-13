#pragma once
#include "RenderAPI/RenderAbstraction.h"

namespace Proto{
	class openGLRenderer : public RenderAbstraction {
		virtual void DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, float lineWidth) override;
		virtual void ClearWindow() override;

	};
}