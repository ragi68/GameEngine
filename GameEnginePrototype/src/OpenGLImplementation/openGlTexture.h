#pragma once
#include "RenderAPI/TextureAbstraction.h"

 //stb/clmg addon

namespace Proto {
	class openGlTexture3D : public Texture3D {
	public:
		openGlTexture3D(const std::string& filePath);

		virtual uint32_t GetWidth() override { return width; }
		virtual uint32_t GetHeight() override { return height; }
		virtual uint32_t GetDepth() override { return depth; }

		virtual void BindTexture(uint32_t spot) override;

	private:
		std::string filePath;
		int width, height, depth, channel;
		uint32_t programID; 
	};

	class openGlTexture2D : public Texture2D {
	public:
		openGlTexture2D(const std::string& filePath);
		~openGlTexture2D(); 
		virtual uint32_t GetWidth() override { return width; }
		virtual uint32_t GetHeight() override { return height; }

		virtual void BindTexture(uint32_t spot) override;

	private:
		std::string filePath;
		int width, height, channel;
		uint32_t programID; 

		
	};
}