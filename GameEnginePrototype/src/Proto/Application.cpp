#include "PrecompiledHeaders.h"
#include "Application.h"
#include "glm/gtx/string_cast.hpp"
#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"



namespace Proto {

	Application* Application::s_Instance = nullptr; //makes sure app is not a singleton-dependent -- makes sure there is only one instance of the window/app.
	Application::Application()  { //-1.0f, 1.0f, -1.0f, 1.0f ; glm::radians(60.0f), 16.0f/9.0f, 100.0f, 0.1f

		
		PROTO_CORE_LOG(!s_Instance, "App is already open.");  //sets app to singleton as a whole, not just as a window but as in openings of the app
		s_Instance = this;									  //creates a unique pointer to window to solidfy if on server side and also a solid imGui layer on server side since we don't want it it to be controlled by the engine, but by us made manually as an essential service. 
		window = std::unique_ptr<AbstractWin>(AbstractWin::windowGenerator());
		window->EventCallBack(std::bind(&Application::Event, this, std::placeholders::_1));
		imguiLayer = new IMGUI_Layer();
		PushLayer(imguiLayer); //pushes layer into the stack. 

		
		//renderer.reset(RenderAbstraction::CreateRenderer()); 
		//
		//v_Array.reset(VertexArrayAbstraction::CreateVertexArray());

		//

		//float vertecies[4 * 7] = { //remember that the z-axis is flipped for our camera. also keep auto camera nera plane value as close to zero as possible. 
		//	-2.0f, -2.0f, -1.0f, 0.6f, 0.23f, 0.19f, 1,
		//	2.0f, -2.0f, -3.0f, 0.8f, 0.9f, 0.35f, 1,
		//	0.0f, 1.0f, -5.0f, 0.25f, 0.6f, 0.7f, 1,
		//	0.0f, -1.0f, 2.0f, 0.6f, 0.7f, 0.8f, 1
		//};


		//v_Buffer.reset(VertexBufferAbstraction::CreateVertexBuffer(vertecies, sizeof(vertecies)));
		///*idk y but the memory size needs to be passed in manually like bro what? - nvm i forgor sizeof only takes in the size of type, so it
		//can't eval the entire thing. */

		//BufferLayout buffers = {
		//	{"a_position", Shader::f3},
		//	{"a_color", Shader::f4}
		//};

		//BufferLayout layout(buffers);
		//v_Buffer->SetBufferLayout(layout);//needed to make sure the addvertexBuffer function works; else nothing happens


		//v_Array->AddVertexBuffer(v_Buffer);


		//

		//unsigned int indicies[6] = { 0, 1 ,2, 2, 3, 0};

		//i_Buffer.reset(IndexBufferAbstraction::CreateIndexBuffer(indicies, sizeof(indicies))); 
		//v_Array->AddIndexBuffer(i_Buffer);

		//std::string vectorShaders = R"(
		//	#version 330 core
		//	layout(location = 0) in vec3 a_position;
		//	layout(location = 1) in vec4 a_color; 

		//	uniform mat4 v_matrix; 

		//	out vec3 v_position; 
		//	out vec4 v_color;


		//	void main(){
		//		v_position = a_position; 
		//		v_color = a_color;
		//		gl_Position = v_matrix * vec4(a_position, 1); 
		//	}
		//)"; //4th coordinate in glPosition is the 'scale'. The lower the value, the more zoomed in the iamge will be. 

		//std::string fragmentShaders = R"(
		//	#version 330 core
		//	layout(location = 0) out vec4 color;

		//	in vec3 v_position;
		//	in vec4 v_color; 

		//	void main(){
		//		color = vec4(v_position + 0.5, 1.0); 
		//		color = v_color;
		//	}
		//)";

		//shader.reset(ShaderAbstraction::CreateShader(vectorShaders, fragmentShaders)); 
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
		//glm::vec3 position = { 0.0f, 0.0f, 10.0f };
		//glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
		while (running) {
		//	
		//	
		//	renderer->ClearWindow();

		//	if (input->checkPressed(KEY_Q)) {
		//		position.z += 0.2f;
		//	}
		//	else if (input->checkPressed(KEY_E)) {
		//		position.z -= 0.2f;
		//	}

		//	if (input->checkPressed(KEY_W)) {
		//		position.y += 0.2f;
		//	} else if (input->checkPressed(KEY_S)) {
		//		 position.y -= 0.2f;
		//	}

		//	if (input->checkPressed(KEY_D)) {
		//		position.x += 0.2f;
		//	}
		//	else if (input->checkPressed(KEY_A)) {
		//		position.x -= 0.2f;
		//	}

		//	if (input->checkPressed(KEY_LEFT)) {
		//		rotation.y += 0.1f;
		//	}else if (input->checkPressed(KEY_RIGHT)) {
		//		rotation.y -= 0.1f;
		//	}

		//	if (input->checkPressed(KEY_UP)) {
		//		rotation.z += 0.1f;
		//	}
		//	else if (input->checkPressed(KEY_DOWN)) {
		//		rotation.z -= 0.1f;
		//	}

		//	if (input->checkPressed(KEY_Z)) {
		//		rotation.x += 0.1f;
		//	}
		//	else if (input->checkPressed(KEY_X)) {
		//		rotation.x -= 0.1f;
		//	}


		//	camera.SetPosition(position);
		//	camera.SetRotation(rotation);

		//	shader->Bind();
		//	v_Array->Bind();
		//	
		//	shader->BindMatrixData("v_matrix", camera.GetVPMatrix()); //camera.GetVPMatrix(); 

		//	renderer->DrawAndEnd(v_Array, 3.4f);

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