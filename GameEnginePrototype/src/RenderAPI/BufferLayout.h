#pragma once
#include <string>
#include <vector>
#pragma once
namespace Proto {

	enum class Shader {
		none = 0, f1, f2, f3, f4, m3, m4, i1, i2, i3, i4, Bool
	};


	static uint32_t GetShaderSize(Shader shader) {
		switch(shader){
			case Shader::f1:	return 4;
			case Shader::f2:	return 8;
			case Shader::f3:	return 12;
			case Shader::f4:	return 16;
			case Shader::m3:	return 36;
			case Shader::i1:	return 4;
			case Shader::i2:	return 8;
			case Shader::i3:	return 12;
			case Shader::i4:	return 16;
			case Shader::m4:	return 64;
			case Shader::Bool:	return 1;
		}

		return 0; 
	}
	class Buffers {
	public:

		Buffers(){}

		std::string name; uint32_t size; bool normalized; size_t offset; Shader shader;


		Buffers(std::string name, Shader shader) : name(name), shader(shader), offset(0), normalized(false), size(GetShaderSize(shader)) {
			//cant handle multi-value????
		}

		uint32_t GetSize(Shader shader) { return GetShaderSize(shader); }

		const int GetCount(Shader shader) {
			switch (shader) {
			case Shader::f1:	return 1;
			case Shader::f2:	return 2;
			case Shader::f3:	return 3;
			case Shader::f4:	return 4;
			case Shader::m3:	return 9;
			case Shader::i1:	return 1;
			case Shader::i2:	return 2;
			case Shader::i3:	return 3;
			case Shader::i4:	return 4;
			case Shader::m4:	return 16;
			case Shader::Bool:	return 1;
			}

			return 0;
		}
	};
	class BufferLayout { //shoudld've commented when I made this -_-
	public:
		
		BufferLayout(){} 

		BufferLayout(std::initializer_list<Buffers> bufferList) : bufferList(bufferList) { //initializer list uses stack alloc - better memory optimization for faster applications  - is auto-caste to std::vector
			CalculateStrideAndOffset();
		}

		const std::vector<Buffers> GetBuffers() { return bufferList; }


		std::vector<Buffers>::iterator begin() { return bufferList.begin(); }
		std::vector<Buffers>::iterator end() { return bufferList.end(); }

		

		

		void CalculateStrideAndOffset() {
			uint32_t offset = 0;
			stride = 0;

			for (Buffers& i : bufferList) {
				i.offset = offset;
				offset += i.size; //caant use sizeof - wrong number
				stride += i.size; 
			}

		}
		
		std::vector<Buffers> bufferList;
		uint32_t stride; 

		

		
	};
}