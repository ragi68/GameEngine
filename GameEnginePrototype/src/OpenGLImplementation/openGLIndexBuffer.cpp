#include "PrecompiledHeaders.h"
#include "openGLIndexBuffer.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

Proto::openGLIndexBuffer::openGLIndexBuffer(uint32_t* indices, uint32_t size)
{
	glGenBuffers(1, &program);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, program);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

Proto::openGLIndexBuffer::~openGLIndexBuffer()
{
	glDeleteBuffers(1, &program);
}

void Proto::openGLIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, program);
}

void Proto::openGLIndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
