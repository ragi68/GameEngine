#include "PrecompiledHeaders.h"
#include "TextureAbstraction.h"
#include "OpenGLImplementation/openGLTexture.h"
#include "RenderAbstraction.h"

namespace Proto {
	Texture2D* Texture2D::Create2DTexture(const std::string& texture) {
		switch (RenderAbstraction::GetAPIType()) {
		case API_Type::none:	return nullptr;
		case API_Type::openGL:	return new openGLTexture2D(texture);
		}

		PROTO_CORE_LOG(false, "No vertex array compatible with any renderer API");
		return nullptr;
	}
}