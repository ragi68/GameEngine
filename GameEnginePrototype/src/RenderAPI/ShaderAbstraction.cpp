#include "PrecompiledHeaders.h"
#include "ShaderAbstraction.h"

#include "OpenGLImplementation/openGLShader.h"
#include "RenderAbstraction.h"

namespace Proto {

	

	ShaderAbstraction* ShaderAbstraction::CreateShader(std::string v_Shader, std::string f_Shader)
	{
		switch (RenderAbstraction::GetAPIType()) {
			case API_Type::none:	PROTO_CORE_LOG(false, "Renderer not supported"); return nullptr;
			case API_Type::openGL:	return new openGLShader(v_Shader, f_Shader);
		}

		return nullptr;
	}

}
