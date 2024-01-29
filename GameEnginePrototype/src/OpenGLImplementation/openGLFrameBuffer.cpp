#include "PrecompiledHeaders.h"
#include "openGLFrameBuffer.h"

#include "glad/glad.h"

namespace Proto {
	openGLFrameBuffer::openGLFrameBuffer(uint32_t size) : size(size){
		glCreateFramebuffers(size, &program);
	}

	void openGLFrameBuffer::Bind() {
		glBindFramebuffer(program, GL_FRAMEBUFFER);
	}

	void openGLFrameBuffer::UnBind() {
		glBindBuffer(program, 0);
	}

	void openGLFrameBuffer::AddFrameBuffer() {

	}

	void openGLFrameBuffer::GetFrameBuffer() {

	}

	void openGLFrameBuffer::SetFrameBuffer() {

	}
}