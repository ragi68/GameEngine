#include "PrecompiledHeaders.h"
#include "Application.h"

#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"



namespace Proto {

	Application* Application::s_Instance = nullptr; //makes sure app is not a singleton-dependent -- makes sure there is only one instance of the window/app.
	Application::Application() : camera(45.0f, (float)(16 / 9), -1.0f, 1.0f) {

		PROTO_CORE_LOG(!s_Instance, "App is already open.");  //sets app to singleton as a whole, not just as a window but as in openings of the app
		s_Instance = this;									  //creates a unique pointer to window to solidfy if on server side and also a solid imGui layer on server side since we don't want it it to be controlled by the engine, but by us made manually as an essential service. 
		window = std::unique_ptr<AbstractWin>(AbstractWin::windowGenerator());
		window->EventCallBack(std::bind(&Application::Event, this, std::placeholders::_1));
		imguiLayer = new IMGUI_Layer();
		PushLayer(imguiLayer); //pushes layer into the stack. 

		//basic render - triangle creation -> vertex array, vertex buffers, vertex shaders
		//below code is copied code from official docs to create a simple triangle w/ glfw. 

		renderer.reset(RenderAbstraction::CreateRenderer()); 

		v_Array.reset(VertexArrayAbstraction::CreateVertexArray());

		

		float vertecies[3 * 7] = {
			-0.5f, -0.5f, 0, 0.7f, 0.8f, 0.8f, 1,
			0.5f, -0.5f, 0, 0, 1, 0.1f, 1,
			0, 0.5f, 0.5f, 0, 0.2f, 1, 1,
		};

		v_Buffer.reset(VertexBufferAbstraction::CreateVertexBuffer(vertecies, sizeof(vertecies)));
		/*idk y but the memory size needs to be passed in manually like bro what? - nvm i forgor sizeof only takes in the size of type, so it
		can't eval the entire thing. */

		BufferLayout buffers = {
			{"a_position", Shader::f3},
			{"a_color", Shader::f4}
		};

		BufferLayout layout(buffers);
		v_Buffer->SetBufferLayout(layout);//needed to make sure the addvertexBuffer function works; else nothing happens


		v_Array->AddVertexBuffer(v_Buffer);


		

		unsigned int indicies[3] = { 0, 1 ,2 };

		i_Buffer.reset(IndexBufferAbstraction::CreateIndexBuffer(indicies, sizeof(indicies))); 
		v_Array->AddIndexBuffer(i_Buffer);

		std::string vectorShaders = R"(
			#version 330 core
			layout(location = 0) in vec3 a_position;
			layout(location = 1) in vec4 a_color; 

			uniform mat4 v_matrix; 

			out vec3 v_position; 
			out vec4 v_color;


			void main(){
				v_position = a_position; 
				v_color = a_color;
				gl_Position = v_matrix * vec4(a_position, 1.0);
			}
		)";

		std::string fragmentShaders = R"(
			#version 330 core
			layout(location = 0) out vec4 color;

			in vec3 v_position;
			in vec4 v_color; 

			void main(){
				color = vec4(v_position + 0.5, 1.0); 
				color = v_color;
			}
		)";

		shader.reset(ShaderAbstraction::CreateShader(vectorShaders, fragmentShaders)); 
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

			renderer->ClearWindow();

			shader->Bind();
			v_Array->Bind();

			shader->BindMatrixData("v_matrix", camera.GetVPMatrix());

			renderer->DrawAndEnd(v_Array, 3.4f);

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