#pragma once
#include "EntryCore.h"
#include "EventSystem/EventHeader.h"
#include "Window.h"
#include "Proto/EventSystem/AppEvent.h"
#include "Stackable.h"

namespace Proto {
	class PROTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RunApp();

		void Event(Events& e);

		//layer push/pop
		void PushLayer(LayerClass* layer);
		void PushBelowLayer(LayerClass* layer);

	private:
		bool WindowClose(CloseWindow& event);
		std::unique_ptr<AbstractWin> window;
		bool running = true;
		Stackable layer_stack;
	};


	Application* StartUp();
}
