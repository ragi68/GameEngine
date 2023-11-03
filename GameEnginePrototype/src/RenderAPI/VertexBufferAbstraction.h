#pragma once

namespace Proto {
	class VertexBufferAbstraction
	{
		
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static VertexBufferAbstraction* CreateVertexBuffer(float* vertices, uint32_t size);
	};
}

