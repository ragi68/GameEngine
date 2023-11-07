#include "PrecompiledHeaders.h"
#include "VertexBufferAbstraction.h"

#include "OpenGLImplementation/openGLVertexBuffer.h"
#include "RenderAbstraction.h"

namespace Proto {
	VertexBufferAbstraction* VertexBufferAbstraction::CreateVertexBuffer(float* vertices, uint32_t size)
	{
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:		PROTO_ERROR_MODULE("No renderer selected"); return nullptr;
			case API_Type::openGL:		return new openGLVertexBuffer(vertices, size); 


		}

		PROTO_CORE_LOG(false, "Renderer not working");
		return nullptr;

	}
}