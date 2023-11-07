#pragma once
#include <string>


namespace Proto {
	class ShaderAbstraction
	{
	public: 

		static ShaderAbstraction* CreateShader(std::string v_Shader, std::string f_Shader);
		virtual void Bind() = 0;
		virtual void Unbind() = 0; 
	};

}

