#pragma once
#include "Proto/LayerClass.h"
namespace Proto {
	class PROTO_API IMGUI_Layer : public LayerClass {
	public:
		IMGUI_Layer();
		~IMGUI_Layer();

		void Update();
		void OnEvent(Events& event);
		void OnStack();
		void OnPop();

	private:
		float m_time = 0.0f;

	};
}

