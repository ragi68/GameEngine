#pragma once
#include "Proto/EntryCore.h"
#include <string>
namespace Proto {
	class Texture2D {
	public:
		Texture2D() = default;

		virtual void Bind(int spot) = 0;
		virtual void UnBind() = 0;

		virtual void ChangeTexture(const std::string& path) = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;


		static Texture2D* Create2DTexture(const std::string& s);
	};

	class Texture3D {

	};
}