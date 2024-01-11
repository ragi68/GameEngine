#pragma once
#include <string>
#include "Proto/EntryCore.h"

namespace Proto {
	class Texture {
	public:
		virtual uint32_t GetHeight() = 0;
		virtual uint32_t GetWidth() = 0;

		virtual void BindTexture(uint32_t spot) = 0;
	};

	class Texture3D : public Texture {
	public:
		Texture3D() = default;
		virtual uint32_t GetDepth() = 0; 
		static Texture3D* CreateTexture(std::string& filePath);
	};


	class Texture2D : public Texture {
	public:
		Texture2D() = default;
		static Texture2D* CreateTexture(std::string & filePath);
	};
}