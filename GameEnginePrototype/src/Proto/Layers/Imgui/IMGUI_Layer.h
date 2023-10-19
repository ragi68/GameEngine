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

		void Update();
		void OnEvent(Events& event);
		void OnStack();
		void OnPop();
		void OnRender();

	private:   
		bool OnMouseDown(MouseDown& e);
		bool OnKeyPressed(KeyPressed& e);
		bool OnMouseUp(MouseUp& e);
		bool OnKeyReleased(KeyRelease& e);
		bool OnWindowClose(CloseWindow& e);
		bool OnWindowResize(WindowResize& e);
		bool OnMouseMove(MouseMoved& e);
		bool OnMouseScroll(MouseScroll& e);
		//bool OnCharQueue(); //have list of chars backed up and ready to type????
	private:
		float m_time = 0.0f;

	};
}

