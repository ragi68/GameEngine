#include "PrecompiledHeaders.h"
#include "RenderAbstraction.h"

namespace Proto {
#define PROTO_RENDER_SET_API(type) API_Type RenderAbstraction::api = API_Type::type;

	PROTO_RENDER_SET_API(openGL);


	void RenderAbstraction::Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
		//set swapchain per render but check for common code - if none, just create more scripts for each one
	}


}