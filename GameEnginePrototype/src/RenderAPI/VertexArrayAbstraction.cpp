#include "PrecompiledHeaders.h"
#include "VertexArrayAbstraction.h"
#include "RenderAbstraction.h"
#include "OpenGLImplementation/openGLVertexArray.h"

namespace Proto {
	VertexArrayAbstraction* VertexArrayAbstraction::CreateVertexArray() {
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:	return nullptr;
			case API_Type::openGL:	return new openGLVertexArray();
		}

		PROTO_CORE_LOG(false, "No vertex array compatible with any renderer API");
		return nullptr; 
	}
}