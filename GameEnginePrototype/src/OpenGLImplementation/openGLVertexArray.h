#pragma once
#include "RenderAPI/VertexArrayAbstraction.h"

namespace Proto {
	class openGLVertexArray : public VertexArrayAbstraction {
	public: 
		openGLVertexArray();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void AddVertexBuffer(std::shared_ptr<VertexBufferAbstraction>& v_Buffer) override;
		virtual void AddIndexBuffer(std::shared_ptr<IndexBufferAbstraction>& i_Buffer) override;


		uint32_t program;

	};
}