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

		virtual uint32_t GetSize() { return size;  }
	public: 
		uint32_t program;
		uint32_t size; 

		
	};
}

