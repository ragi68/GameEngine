#pragma once
#include "RenderAPI/TextureAbstraction.h"

namespace Proto {
	class openGLTexture2D : public Texture2D {
	public:
		openGLTexture2D(const std::string& s);

		virtual void Bind(uint32_t spot = 0) override;

		virtual void UnBind() override;

		virtual void SetTexture(const std::string& path) override; 

		virtual int GetWidth() override { return width; }
		virtual int GetHeight() override { return height; }
	public: 
		std::string t_path;

	private:
		uint32_t program;
		
		int width, height, channels;
	};
}
