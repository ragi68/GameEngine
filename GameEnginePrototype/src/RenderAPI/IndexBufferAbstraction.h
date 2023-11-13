#pragma once


namespace Proto {
	class IndexBufferAbstraction {
	public:
		static IndexBufferAbstraction* CreateIndexBuffer(uint32_t* indices, uint32_t size);
		virtual void Bind() = 0;
		virtual void Unbind() = 0; 

		virtual uint32_t GetSize() = 0;

		uint32_t program;
	};

}