#pragma once
#include "Proto/EntryCore.h"
namespace Proto {

	class FrameBuffers {
	public:
		FrameBuffers() = default;

		virtual uint32_t GetWidth() = 0;
		virtual void GetFrameBuffer() = 0;
		virtual void SetFrameBuffer() = 0;
		virtual void AddFrameBuffer() = 0;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		static FrameBuffers* CreateFrameBuffer(uint32_t size);

		

	};
}