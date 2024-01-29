#include "PrecompiledHeaders.h"
#include "GetError.h"
#include "RenderAbstraction.h"
#include "OpenGLImplementation/openGLGetErrors.h"

namespace Proto {
    Error* Proto::Error::SeeError()
    {
		switch (RenderAbstraction::GetAPIType()) {
		case API_Type::none:		PROTO_ERROR_MODULE("No renderer selected"); return nullptr;
		case API_Type::openGL:		return new openGLErrors();

		}

		return nullptr;
    }

}
