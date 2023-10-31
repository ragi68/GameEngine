#pragma once

namespace Proto {
	class rendercontext {
	public: 
		virtual void Init() = 0;
		virtual void SwapBuffer() = 0;

		//static rendercontext CreateRenderer(void* window); 
	};
}