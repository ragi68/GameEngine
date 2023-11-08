#pragma once
#include "RenderAPI/RenderAbstraction.h"

namespace Proto{
	class openGLRenderer : public RenderAbstraction {
		virtual void Draw(VertexArrayAbstraction& v_Array, uint32_t vertecies, float lineWidth) override;
		virtual void ClearWindow() override;

		virtual void Begin() override;
		virtual void End() override;
		virtual void Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override; 
	};
}