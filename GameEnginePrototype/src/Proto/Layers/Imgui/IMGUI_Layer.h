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

		virtual void OnStack() override; //add to stack
		virtual void OnPop() override; //pop from stack
		virtual void Render() override; //show windows
		
		virtual void Init_Layer(); //start creating frame
		virtual void End_Layer(); //finish frame rendering. 

		//bool OnCharQueue(); //have list of chars backed up and ready to type????
	private:
		float m_time = 0.0f;

	};
}

