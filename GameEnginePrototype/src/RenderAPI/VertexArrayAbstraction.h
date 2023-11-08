#pragma once
#include <memory>
#include "VertexBufferAbstraction.h"
#include "IndexBufferAbstraction.h"

namespace Proto {
	class VertexArrayAbstraction {
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void AddVertexBuffer(std::shared_ptr<VertexBufferAbstraction>& v_Buffer) = 0;
		virtual void AddIndexBuffer(std::shared_ptr<IndexBufferAbstraction>& i_Buffer) = 0;

		static VertexArrayAbstraction* CreateVertexArray(); 

	};
}