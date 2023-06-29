#pragma once
#include "EntryCore.h"
#include "EventSystem/EventHeader.h"
#include "Window.h"
#include "Proto/EventSystem/AppEvent.h"

namespace Proto {
	class PROTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RunApp();

		void Event(Events& e);
	private:
		bool WindowClose(CloseWindow& event);
		std::unique_ptr<AbstractWin> window;
		bool running = true;
	};


	Application* StartUp();
}
