#pragma once
#include "RenderAPI/VertexBufferAbstraction.h"
namespace Proto {
	class openGLVertexBuffer : public VertexBufferAbstraction
	{
	public:
		openGLVertexBuffer(float* vertecies, uint32_t size);
		~openGLVertexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual BufferLayout& GetLayout() override {
			return layout;
		}

		virtual void SetBufferLayout(BufferLayout& newLayout) override {
			layout = newLayout;
		}



		uint32_t program; 
		BufferLayout layout;
	};

}

