#include "PrecompiledHeaders.h"
#include "TextureAbstraction.h"
#include "RenderAPI/RenderAbstraction.h"
#include "OpenGLImplementation/openGlTexture.h"

namespace Proto {
	Texture3D* Texture3D::CreateTexture(std::string& filePath) {
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:	return nullptr;
		}

		return nullptr;
	}

	Texture2D* Texture2D::CreateTexture(std::string& filePath) {
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:	return nullptr;
			case API_Type::openGL:  return new openGlTexture2D(filePath); //fix this inheritance conversion issue
		}

		return nullptr;
	}
}