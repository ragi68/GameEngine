#pragma once
#include "Proto/EntryCore.h"
#include "Proto/logging.h"
//relevant lib includes
#include "glm/glm.hpp"


namespace Proto {

	enum class API_Type {
		none = 0, openGL = 1, direct3D = 2, vulkan = 3
	};
	class RenderAbstraction {
	public:
		

		virtual void Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0; //initialize renderer & set viewport
		virtual void Begin() = 0; //start renderer
		virtual void End() = 0; //end renderer??? or finish setting up renderer

		inline static API_Type GetAPIType() { return api; }
		//static RenderAbstraction CreateRenderer(); 
	private:
		static API_Type api;
	};
}

