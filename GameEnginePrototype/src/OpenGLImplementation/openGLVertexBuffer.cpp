#include "PrecompiledHeaders.h"
#include "openGLVertexBuffer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Proto {

	
	
	openGLVertexBuffer::openGLVertexBuffer(float* vertecies, uint32_t size)
	{
		glCreateBuffers(1, &program);
		glBindBuffer(GL_ARRAY_BUFFER, program);
		glBufferData(GL_ARRAY_BUFFER, size, vertecies, GL_STATIC_DRAW);
	}

	openGLVertexBuffer::~openGLVertexBuffer()
	{
		glDeleteBuffers(1, &program); 
	}
	void openGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, program);

	}
	void openGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}