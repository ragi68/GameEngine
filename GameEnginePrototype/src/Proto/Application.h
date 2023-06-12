#pragma once
#include "EntryCore.h"
#include "EventSystem/EventHeader.h"


namespace Proto {
	class PROTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RunApp();
	};

	Application* StartUp();
}
