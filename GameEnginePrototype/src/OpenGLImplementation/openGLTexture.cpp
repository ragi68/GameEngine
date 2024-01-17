#include "PrecompiledHeaders.h"
#include "openGlTexture.h"

#include "CLMG.h"

#include <glad/glad.h>
using namespace cimg_library;


namespace Proto {
	openGlTexture3D::openGlTexture3D(std::string& filePath) : filePath(filePath) {
		
	}

	void openGlTexture3D::BindTexture(uint32_t spot)
	{
	}

	openGlTexture2D::openGlTexture2D(std::string& filePath) : filePath(filePath) {
		CImg<unsigned char> image("TestCat.avif");
		height = image.height();
		width = image.width();

		glCreateTextures(GL_TEXTURE_2D, 1, &programID);
		glTextureStorage2D(programID, 1, GL_RGB8, width, height);

		glTextureParameteri(programID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(programID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureSubImage2D(programID, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);
	}

	openGlTexture2D::~openGlTexture2D() {
		glDeleteTextures(1, &programID);
	}

	void openGlTexture2D::BindTexture(uint32_t spot) {
		glBindTextureUnit(spot, programID);
	}
}