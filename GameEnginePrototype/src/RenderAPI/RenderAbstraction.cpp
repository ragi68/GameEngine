#include "RenderAbstraction.h"
#include "PrecompiledHeaders.h"


namespace Proto {
//#define PROTO_WINDOWS() RenderAbstraction::API_Type RenderAbstraction::api = RenderAbstraction::API_Type::openGL; //switch name to PROTO_RENDER_WINDOWS
//#define PROTO_WINDOWS_OPTIMIZED() RenderAbstraction::API_Type RenderAbstraction::api = RenderAbstraction::API_Type::direct3D;
//#define PROTO_LINUX() RenderAbstraction::API_Type RenderAbstraction::api = RenderAbstraction::API_Type::vulkan;
//#define PROTO_MACOS()  RenderAbstraction::API_Type RenderAbstraction::api = RenderAbstraction::API_Type::vulkan;
//fix macros for future use

	void RenderAbstraction::Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
		return;
	}


	//RenderAbstraction RenderAbstraction::CreateRenderer() {
	//	switch (api) {
	//	case RenderAbstraction::API_Type::none:           PROTO_ERROR_MODULE("NO rendering API detected"); return nullptr;
	//	case RenderAbstraction::API_Type::openGL:         PROTO_INFO_MODULE("OpenGL initialized");


	//	}
	// }

}