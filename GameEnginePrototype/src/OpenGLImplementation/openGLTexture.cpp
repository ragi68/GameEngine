#include "PrecompiledHeaders.h"
#include "openGlTexture.h"

#include "stb_image.h"

#include <glad/glad.h>



namespace Proto {
	openGlTexture3D::openGlTexture3D(const std::string& filePath) : filePath(filePath) {
		
	}

	void openGlTexture3D::BindTexture(uint32_t spot)
	{
	}

	openGlTexture2D::openGlTexture2D(const std::string& filePath) : filePath(filePath) {
		stbi_uc* image = stbi_load(filePath.c_str(), &width, &height, &channel, 0);

		glCreateTextures(GL_TEXTURE_2D, 1, &programID);
		glTextureStorage2D(programID, 1, GL_RGB8, width, height);

		glTextureParameteri(programID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(programID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureSubImage2D(programID, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);

		stbi_image_free(image);
	}

	openGlTexture2D::~openGlTexture2D() {
		glDeleteTextures(1, &programID);
	}

	void openGlTexture2D::BindTexture(uint32_t spot) {
		glBindTextureUnit(spot, programID);
	}


}