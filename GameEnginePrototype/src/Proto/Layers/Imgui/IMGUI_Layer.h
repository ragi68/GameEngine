#pragma once
#include "Proto/LayerClass.h"
#include "Proto/EventSystem/Keys.h"
#include "Proto/EventSystem/MouseEvent.h"
#include "Proto/EventSystem/EventHeader.h"
#include "Proto/EventSystem/AppEvent.h"

namespace Proto {
	class PROTO_API IMGUI_Layer : public LayerClass {
	public:
		IMGUI_Layer();
		~IMGUI_Layer();

		virtual void Update() override;
		virtual void OnStack() override;
		virtual void OnPop() override;
		virtual void Render() override;
		
		virtual void Init_Layer();
		virtual void End_Layer(); 

		//bool OnCharQueue(); //have list of chars backed up and ready to type????
	private:
		float m_time = 0.0f;

	};
}

