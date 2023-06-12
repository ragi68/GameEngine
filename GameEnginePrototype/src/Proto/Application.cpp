#include "PrecompiledHeaders.h"
#include "Application.h"

#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"

namespace Proto {

	Application::Application() {

	}

	Application::~Application() {

	}
	void Application::RunApp() {

		WindowResize e(1280, 720);
		PROTO_TRACE_MODULE(e);
		while(true);
	}
}