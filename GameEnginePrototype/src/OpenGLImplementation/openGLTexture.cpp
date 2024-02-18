#include "PrecompiledHeaders.h"
#include "openGLTexture.h"
#include <glad/glad.h>
#include "stb_image.h"
namespace Proto {
	openGLTexture2D::openGLTexture2D(const std::string& path) : t_path(path) {

		int w, h, c;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &w, &h, &c, 0);
		width = w; height = h;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glCreateTextures(GL_TEXTURE_2D, 1, &program); 

		GLenum internalFormat = 0, dataFormat = 0; 
		internalFormat = c == 4 ? GL_RGBA8 : GL_RGB8;
		dataFormat = c == 4 ? GL_RGBA : GL_RGB;
		
		glTextureStorage2D(GL_TEXTURE_2D, 1, internalFormat, width, height);
		glBindTexture(GL_TEXTURE_2D, program); 


		glTextureParameteri(program, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(program, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data); 

		

		stbi_image_free(data); 

	}

	void openGLTexture2D::Bind(uint32_t spot) {
		glBindTextureUnit(spot, program);
	}

	void openGLTexture2D::UnBind() {
		glDeleteTextures(1, &program);
	}

	void openGLTexture2D::SetTexture(const std::string& path){
		t_path = path;
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels,0);

		GLenum internalFormat = 0, dataFormat = 0;
		internalFormat = channels == 4 ? GL_RGBA8 : GL_RGB8;
		dataFormat = channels == 4 ? GL_RGBA : GL_RGB;

		glTexSubImage2D(program, 0, 0, 0, width, height, internalFormat, GL_UNSIGNED_BYTE, data);

		glBindTexture(GL_TEXTURE_2D, program);

		stbi_image_free(data);

	}
}