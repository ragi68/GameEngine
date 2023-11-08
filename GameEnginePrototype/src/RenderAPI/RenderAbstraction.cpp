#include "PrecompiledHeaders.h"
#include "RenderAbstraction.h"
#include "OpenGLImplementation/openGLRenderer.h"

namespace Proto {
#define PROTO_RENDER_SET_API(type) API_Type RenderAbstraction::api = API_Type::type;


#ifdef PROTO_PLATFORM_WINDOWS
	PROTO_RENDER_SET_API(openGL);
#else
	PROTO_CORE_LOG(false, "NO RENDERER CHOSEN - PLEASE CHOOSE RENDER OPTION ABOVE THRU OS OR MANUAL");
	PROTO_RENDER_SET_API(none); 
#endif



	RenderAbstraction* RenderAbstraction::CreateRenderer() {
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:	return nullptr;
			case API_Type::openGL:	return new openGLRenderer(); 
		}

		return nullptr;
	}

}