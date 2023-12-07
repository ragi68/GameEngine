#pragma once
#include "EntryCore.h"
#include "Window.h"
#include "Stackable.h"
#include "EventSystem/EventHeader.h"
#include "Layers/Imgui/IMGUI_Layer.h"
#include "Proto/EventSystem/AppEvent.h"
#include "Time.h"


namespace Proto {
	class PROTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RunApp();

		void Event(Events& e);

		inline static Application& Get() {
			return *s_Instance;
		}

		//layer push/pop
		void PushLayer(LayerClass* layer);
		void PushBelowLayer(LayerClass* layer);

		inline AbstractWin& GetRef() {
			return *window;
		}

	private:
		bool WindowClose(CloseWindow& event);
		std::shared_ptr<AbstractWin> window;
		Time time; 
		IMGUI_Layer* imguiLayer; 
		bool running = true;
		Stackable layer_stack;
		static Application* s_Instance;

		float frameTime = 0;
		float inTime = 0; 

	};


	Application* StartUp();
}
