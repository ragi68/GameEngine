#pragma once


namespace Proto {
	class IndexBufferAbstraction {
		virtual void Create(unsigned int indices) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0; 


	};

}