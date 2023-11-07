#pragma once
#include "RenderAPI/IndexBufferAbstraction.h"
namespace Proto{
	class openGLIndexBuffer : public IndexBufferAbstraction
	{
	public:
		openGLIndexBuffer(uint32_t* indices, uint32_t size);
		~openGLIndexBuffer();
		virtual void Bind() override;
		virtual void Unbind() override;

		uint32_t program;

		
	};
}

