#include "PrecompiledHeaders.h"
#include "openGLVertexArray.h"
#include "glad/glad.h"


namespace Proto {

	static GLenum ShaderType(Shader shader) {
		switch (shader) {
		case Shader::Bool:	return GL_BOOL;
		case Shader::m3:	return GL_FLOAT;
		case Shader::m4:	return GL_FLOAT;
		case Shader::f1:	return GL_FLOAT;
		case Shader::f2:	return GL_FLOAT;
		case Shader::f3:	return GL_FLOAT;
		case Shader::f4:	return GL_FLOAT;
		case Shader::i1:	return GL_INT;
		case Shader::i2:	return GL_INT;
		case Shader::i3:	return GL_INT;
		case Shader::i4:	return GL_INT;
		}

		return 0;
	}

	openGLVertexArray::openGLVertexArray()
	{
 
		glGenVertexArrays(1, &program);
		glBindVertexArray(program);
	}

	void openGLVertexArray::Bind()
	{
		glBindVertexArray(program);
	}

	void openGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	


	void openGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBufferAbstraction>& v_Buffer)
	{
		glBindVertexArray(program);
		v_Buffer->Bind();

		BufferLayout& layout = v_Buffer->GetLayout(); 
		auto l = layout.GetBuffers(); 
		uint8_t index = 0; 
		for (Buffers& a : l) {
			switch (a.shader) {
				case Shader::f1: return;
				case Shader::f2: return;
				case Shader::f3: {
					glEnableVertexAttribArray(index);
					glVertexAttribPointer(index, l[index].GetCount(l[index].shader), ShaderType(l[index].shader), l[index].normalized ? GL_TRUE : GL_FALSE, layout.stride, (const void*)l[index].offset);
					index++;

					break;
				}
				case Shader::f4: {
					glEnableVertexAttribArray(index);
					glVertexAttribPointer(index, l[index].GetCount(l[index].shader), ShaderType(l[index].shader), l[index].normalized ? GL_TRUE : GL_FALSE, layout.stride, (const void*)l[index].offset);
					index++;

					break;
				}



			}
		}

		

	}

	void openGLVertexArray::AddIndexBuffer(std::shared_ptr<IndexBufferAbstraction>& i_Buffer)
	{
		glBindVertexArray(program);
		i_Buffer->Bind(); 
	}


}

