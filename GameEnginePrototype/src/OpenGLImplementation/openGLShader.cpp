
#include "PrecompiledHeaders.h"
#include "openGLShader.h"
#include "glm/gtc/type_ptr.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//straight copy of khronos official documentation
namespace Proto {




	openGLShader::openGLShader(const std::string& vertex, const std::string& fragment){
		// Create an empty vertex shader handle
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); 
		vertex_shader = vertexShader;

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = vertex.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);
			std::cout << "Compile Error: " << std::endl << infoLog[0] << std::endl;
			std::cout << "error";

			// We don't need the shader anymore.
			glDeleteShader(vertexShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Create an empty fragment shader handle
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		fragment_shader = fragmentShader; //set precendent for logger



		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = (const GLchar*)fragment.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// Compile the fragment shader
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled); //checks for fragment shader compilation - 
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			std::cout << "Compile Error: " << std::endl << infoLog[0] << std::endl;

			// We don't need the shader anymore.
			glDeleteShader(fragmentShader);
			// Either of them. Don't leak shaders.
			glDeleteShader(vertexShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.
		program = glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		// Link our program
		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
			std::cout << "Compile Error: " << std::endl << infoLog[0] << std::endl;

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Always detach shaders after a successful link.
		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);
	}

	openGLShader::~openGLShader() {
		glDeleteProgram(program);
	}

	void openGLShader::Bind() {
		glUseProgram(program);
	}

	void openGLShader::Unbind() {
		glUseProgram(0);
	}
	void openGLShader::BindMatrixData(std::string name,  glm::mat4& matrix)
	{
		GLuint shader = glGetUniformLocation(program, name.c_str());
		glUniformMatrix4fv(shader,1 , GL_FALSE, glm::value_ptr(matrix));
	}

	void openGLShader::BindFloat3Data(std::string name, glm::vec3& vector) {
		GLuint shader = glGetUniformLocation(program, name.c_str());
		glUniform3fv(shader, 1, glm::value_ptr(vector)); 
	}

	void openGLShader::BindIntData(std::string name, int a) {
		GLuint shader = glGetUniformLocation(program, name.c_str());
		glUniform1i(shader, a);
	}

	void openGLShader::GetLog() {
		
		glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<GLchar> infoLog(logLength);
		glGetShaderInfoLog(vertex_shader, GLsizei(logLength), &logLength, &infoLog[0]);
		std::cout << "Compiler error:" << infoLog[0];
		
	}
}



