#pragma once
#include "EntryCore.h"
#include "EventSystem/EventHeader.h"
#include "Window.h"

namespace Proto {
	class PROTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RunApp();
	private:
		std::unique_ptr<AbstractWin> window;
		bool running = true;
	};


	Application* StartUp();
}
