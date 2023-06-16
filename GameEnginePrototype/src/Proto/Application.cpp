#include "PrecompiledHeaders.h"
#include "Application.h"

#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"

namespace Proto {

	Application::Application() {
		window = std::unique_ptr<AbstractWin>(AbstractWin::windowGenerator());
	}

	Application::~Application() {

	}
	void Application::RunApp() {

		
		while (running) {
			window->UpdateWindow();
		}
	}
}