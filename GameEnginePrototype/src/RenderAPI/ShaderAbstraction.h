#pragma once
#include <string>

namespace Proto {
	class ShaderAbstraction
	{
	public: 
		virtual void Bind() = 0;
		virtual void Unbind() = 0; 
	};

}

