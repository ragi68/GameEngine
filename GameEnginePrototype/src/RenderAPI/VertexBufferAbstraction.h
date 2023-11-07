#pragma once
#include "BufferLayout.h"
namespace Proto {
	class VertexBufferAbstraction
	{
	public:
		
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual BufferLayout& GetLayout() = 0;
		virtual void SetBufferLayout(BufferLayout& layout) = 0; 
		
		static VertexBufferAbstraction* CreateVertexBuffer(float* vertices, uint32_t size);

	};
}

