#pragma once
#include "RenderAPI/VertexBufferAbstraction.h"
namespace Proto {
	class openGLVertexBuffer : public VertexBufferAbstraction
	{
		openGLVertexBuffer(float* vertecies);
		~openGLVertexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;

		uint32_t program; 
	};

}

