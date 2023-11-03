#pragma once
#include "RenderAPI/VertexBufferAbstraction.h"
namespace Proto {
	class openGLVertexBuffer : public VertexBufferAbstraction
	{
		openGLVertexBuffer(float* vertecies, uint32_t size);
		~openGLVertexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;
	};

}

