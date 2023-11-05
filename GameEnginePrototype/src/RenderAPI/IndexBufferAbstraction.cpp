#include "PrecompiledHeaders.h"

#include "IndexBufferAbstraction.h"
#include "OpenGLImplementation/openGLIndexBuffer.h"
#include "RenderAbstraction.h"


namespace Proto {
	IndexBufferAbstraction* IndexBufferAbstraction::CreateIndexBuffer(uint32_t* indices, uint32_t size)
	{
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:		PROTO_ERROR_MODULE("No renderer selected"); return nullptr;
			case API_Type::openGL:		return new openGLIndexBuffer(indices, size);

		}

		PROTO_CORE_LOG(false, "Renderer not working");
		return nullptr;

	}
}