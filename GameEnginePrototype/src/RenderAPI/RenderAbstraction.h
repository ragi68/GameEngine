#pragma once
#include "Proto/EntryCore.h"
#include "Proto/logging.h"
//relevant lib includes

#include "VertexArrayAbstraction.h"


namespace Proto {

	enum class API_Type {
		none = 0, openGL = 1, direct3D = 2, vulkan = 3
	};


	class RenderAbstraction {
	public:
		

		void Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height); //initialize renderer & set viewport
		void Begin(); //start renderer


		virtual void ClearWindow() = 0;
		virtual void DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, float lineWidth) = 0; 

		inline static API_Type GetAPIType() { return api; }
		static RenderAbstraction* CreateRenderer(); 
	private:
		static API_Type api;
	};
}

