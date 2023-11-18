#pragma once
#include "RenderAPI/ShaderAbstraction.h"


namespace Proto {
	class openGLShader : public ShaderAbstraction {
	public:
		openGLShader(const std::string& vertex, const std::string& fragment);
		~openGLShader();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual void BindMatrixData(std::string name, glm::mat4& matrix) override;

	public:
		unsigned int program; //program ID - noticed that GLUint was used for program ID, so I replaced it with a a direct 
		//uint in order to generalize it


	};
}
