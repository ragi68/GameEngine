#pragma once
#include "Proto/EntryCore.h"
#include "Proto/logging.h"
//relevant lib includes

#include "VertexArrayAbstraction.h"
#include "RenderAPI/ShaderAbstraction.h"


namespace Proto {

	enum class API_Type {
		none = 0, openGL = 1, direct3D = 2, vulkan = 3
	};


	class RenderAbstraction {
	public:
		

		void Init(uint32_t x, uint32_t y, uint32_t width, uint32_t height); //initialize renderer & set viewport
		void Begin(); //start renderer


		virtual void ClearWindow() = 0;
		virtual void DrawAndEnd(std::shared_ptr<VertexArrayAbstraction>& v_Array, glm::mat4& transform, std::shared_ptr<ShaderAbstraction> shader) = 0; //const glm::mat_4 glm::mat4(1.0f);

		inline static API_Type GetAPIType() { return api; }
		static RenderAbstraction* CreateRenderer(); 
	private:
		static API_Type api;
	};
}

