#include "PrecompiledHeaders.h"
#include "FrameBufferAbstraction.h"
#include "PrecompiledHeaders.h"
#include "RenderAbstraction.h"
#include "OpenGLImplementation/openGLFrameBuffer.h"


namespace Proto {
    FrameBuffers* Proto::FrameBuffers::CreateFrameBuffer(uint32_t size)
    {
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:	return nullptr;
			case API_Type::openGL:  return new openGLFrameBuffer(size);
		}
	}
}
