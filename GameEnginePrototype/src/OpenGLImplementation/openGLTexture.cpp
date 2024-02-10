#include "PrecompiledHeaders.h"
#include "openGLTexture.h"
#include <glad/glad.h>
#include "stb_image.h"
namespace Proto {
	openGLTexture2D::openGLTexture2D(const std::string& path) : t_path(path) {
		int w, h, c;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &w, &h, &c, 0);
		glCreateTextures(GL_TEXTURE_2D, 1, &program); //maybe replace with glGenTexture
		width = w; height = h;
		glTextureStorage2D(GL_TEXTURE_2D, 1, GL_RGB8, width, height);
		glBindTexture(GL_TEXTURE_2D, program);

		glTextureParameteri(program, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(program, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		glBindTexture(GL_TEXTURE_2D, program); //binds to spot zero automatically - test bind


		stbi_image_free(data);


	}

	void openGLTexture2D::Bind(int spot) {
		glBindTextureUnit(spot, program);
	}

	void openGLTexture2D::UnBind() {
		glDeleteTextures(1, &program);
	}

	void openGLTexture2D::ChangeTexture(const std::string& path){
		t_path = path;
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, GL_RGB8);

		glTexSubImage2D(program, 0, 0, 0, width, height, GL_RGB8, GL_UNSIGNED_BYTE, data);

		glBindTexture(GL_TEXTURE_2D, program);

		stbi_image_free(data);

	}
}