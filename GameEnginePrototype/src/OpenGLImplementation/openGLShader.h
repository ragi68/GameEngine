#pragma once
#include "RenderAPI/ShaderAbstraction.h"


namespace Proto {
	class openGLShader : public ShaderAbstraction {
	public:
		openGLShader(const std::string& vertex, const std::string& fragment);
		~openGLShader();

		virtual void Bind() override;
		virtual void Unbind() override;
		//add both program and shader logs
		virtual void GetLog() override; 

		virtual void BindMatrixData(std::string name, glm::mat4& matrix) override;
		virtual void BindFloat3Data(std::string name, glm::vec3& vector) override; 
		virtual void BindIntData(std::string name, int a) override;

	public:
		unsigned int program; //program ID - noticed that GLUint was used for program ID, so I replaced it with a a direct 
		//uint in order to generalize it

		uint32_t vertex_shader, fragment_shader;
		int logLength = 0;

		


	};
}
