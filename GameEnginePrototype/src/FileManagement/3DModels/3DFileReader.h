#pragma once
#include <string>
//revamped 3d FILE READER
//maybe use actual library this time?
namespace Proto {
	class FileRead3D {

	public:
		FileRead3D(const std::string& path); 

		virtual void GetTransform() = 0;
		virtual void CreateVertexBuffer() = 0;
		virtual void CreateIndexBuffer() = 0;

		


	private:
		std::string& path;
		


	};

	struct Shape {
		long int triangleCount;
		std::vector<float> coordinates;
		//hopw to represent the coordS????

	};
}