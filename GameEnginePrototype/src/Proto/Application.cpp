#include "PrecompiledHeaders.h"
#include "Application.h"
#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"



namespace Proto {

	Application* Application::s_Instance = nullptr; //makes sure app is not a singleton-dependent -- makes sure there is only one instance of the window/app.
	Application::Application() { //-1.0f, 1.0f, -1.0f, 1.0f ; glm::radians(60.0f), 16.0f/9.0f, 100.0f, 0.1f

		
		PROTO_CORE_LOG(!s_Instance, "App is already open.");  //sets app to singleton as a whole, not just as a window but as in openings of the app
		s_Instance = this;									  //creates a unique pointer to window to solidfy if on server side and also a solid imGui layer on server side since we don't want it it to be controlled by the engine, but by us made manually as an essential service. 
		window = std::unique_ptr<AbstractWin>(AbstractWin::windowGenerator());
		window->EventCallBack(std::bind(&Application::Event, this, std::placeholders::_1));
		imguiLayer = new IMGUI_Layer();
		PushLayer(imguiLayer); //pushes layer into the stack. 

		
		
	}
	void Application::Event(Events& e) {
		EventDispatcher dispatcher(e); //create event dispatch object
		dispatcher.dispatch<CloseWindow>(std::bind(&Application::WindowClose, this, std::placeholders::_1)); //binds dispatcher to event of closing window

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
		


			for (LayerClass* layer : layer_stack)
				layer->Update();

			imguiLayer->Init_Layer();
			for (LayerClass* layer : layer_stack) {
				layer->Render();
			}
			imguiLayer->End_Layer();


			window->UpdateWindow();

		}

	}

	void Application::PushLayer(LayerClass* layers) { //adds layer to layer stack
		layer_stack.PushLayer(layers);
		layers->OnStack();
	}

	void Application::PushBelowLayer(LayerClass* layer) { //adds layer to layer stack 
		layer_stack.PushBelowLayers(layer);
		layer->OnStack();
	}
}