#pragma once
#include <string>
#include "C:\Prototypes\GameEngineProto\GameEnginePrototype\externalLibs\GLM\glm\glm.hpp"


namespace Proto {
	class ShaderAbstraction
	{
	public: 

		static ShaderAbstraction* CreateShader(std::string v_Shader, std::string f_Shader);
		virtual void Bind() = 0;
		virtual void Unbind() = 0; 
		virtual void BindMatrixData(std::string name, glm::mat4& matrix) = 0;
	};

}

