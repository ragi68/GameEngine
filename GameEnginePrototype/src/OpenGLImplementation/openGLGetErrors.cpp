#include "PrecompiledHeaders.h"
#include "openGLGetErrors.h"
#include <glad/glad.h>
namespace Proto {
	void openGLErrors::GetErrors()
	{
		GLenum errors;
		while (errors = glGetError() != GL_NO_ERROR) {
			std::cout << glGetError();
		}
	}
}

