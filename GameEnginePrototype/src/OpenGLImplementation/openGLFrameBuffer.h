#pragma once

#include "RenderAPI/FrameBufferAbstraction.h"

namespace Proto {

	class openGLFrameBuffer : public FrameBuffers {
	public:
		openGLFrameBuffer(uint32_t n);

		virtual uint32_t GetWidth() override;

		virtual void Bind() override;
		virtual void UnBind() override;

		virtual void GetFrameBuffer() override;
		virtual void SetFrameBuffer() override;
		virtual void AddFrameBuffer() override;

		
	private:
		uint32_t program;
		uint32_t size;
	};

}
