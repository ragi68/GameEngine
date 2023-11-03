#include "PrecompiledHeaders.h"
#include "openGLVertexBuffer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Proto {
	/*openGLVertexBuffer::openGLVertexBuffer(int vertecies, uint32_t* size)
	{
		glCreateBuffers(vertecies, size);

	}*/
	openGLVertexBuffer::~openGLVertexBuffer()
	{
	}
	void openGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}
	void openGLVertexBuffer::Unbind()
	{
	}
}