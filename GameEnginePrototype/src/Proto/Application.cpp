#include "PrecompiledHeaders.h"
#include "Application.h"

#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"


namespace Proto {

	Application* Application::s_Instance = nullptr; //makes sure app is not a singleton-dependent -- makes sure there is only one instance of the window/app. 

	Application::Application() {

		PROTO_CORE_LOG(!s_Instance, "App is already open."); 
		s_Instance = this;
		window = std::unique_ptr<AbstractWin>(AbstractWin::windowGenerator());
		window->EventCallBack(std::bind(&Application::Event, this, std::placeholders::_1));
		//window->EventCallBack()
	}
	void Application::Event(Events& e) {
		EventDispatcher dispatcher(e); //create event dispatch object
		dispatcher.dispatch<CloseWindow>(std::bind(&Application::WindowClose, this, std::placeholders::_1)); //binds dispatcher to event of closing window
		PROTO_TRACE_MODULE("{0}", e);

		for (auto i = layer_stack.end(); i != layer_stack.begin();) {
			(*--i)->OnEvent(e);
			if (e.m_handled) {
				break; //framebuffer implementation on windows plat code
			}
		}
	}

	bool Application::WindowClose(CloseWindow& event) {
		running = false; //sets window run to false
		return 0;
	}
	Application::~Application() {

	}
	void Application::RunApp() {

		
		while (running) {
			window->UpdateWindow();
			for (LayerClass* layer : layer_stack) {
				layer->Update();
			}
		}

	}

	void Application::PushLayer(LayerClass* layers) {
		layer_stack.PushLayer(layers);
		layers->OnStack(); 
	}

	void Application::PushBelowLayer(LayerClass* layer) {
		layer_stack.PushBelowLayers(layer);
		layer->OnStack(); 
	}
}