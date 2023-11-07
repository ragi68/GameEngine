#include "PrecompiledHeaders.h"
#include "Application.h"
#include <glad/glad.h>
#include "Proto/EventSystem/AppEvent.h"
#include "Proto/logging.h"


namespace Proto {

	Application* Application::s_Instance = nullptr; //makes sure app is not a singleton-dependent -- makes sure there is only one instance of the window/app. 

	static GLenum ShaderType(Shader shader) {
		switch (shader) {
		case Shader::Bool:	return GL_BOOL;
		case Shader::m3:	return GL_FLOAT;
		case Shader::m4:	return GL_FLOAT;
		case Shader::f1:	return GL_FLOAT;
		case Shader::f2:	return GL_FLOAT;
		case Shader::f3:	return GL_FLOAT;
		case Shader::f4:	return GL_FLOAT;
		case Shader::i1:	return GL_INT;
		case Shader::i2:	return GL_INT;
		case Shader::i3:	return GL_INT;
		case Shader::i4:	return GL_INT;
		}

		return 0;
	}


	Application::Application() {

		PROTO_CORE_LOG(!s_Instance, "App is already open.");  //sets app to singleton as a whole, not just as a window but as in openings of the app
		s_Instance = this;									  //creates a unique pointer to window to solidfy if on server side and also a solid imGui layer on server side since we don't want it it to be controlled by the engine, but by us made manually as an essential service. 
		window = std::unique_ptr<AbstractWin>(AbstractWin::windowGenerator());
		window->EventCallBack(std::bind(&Application::Event, this, std::placeholders::_1));
		imguiLayer = new IMGUI_Layer();
		PushLayer(imguiLayer); //pushes layer into the stack. 

		//basic render - triangle creation -> vertex array, vertex buffers, vertex shaders
		//below code is copied code from official docs to create a simple triangle w/ glfw. 
		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		

		float vertecies[3 * 3] = {
			-0.5f, -0.5f, 0,
			0.5f, -0.5f, 0,
			0, 0.5f, 0.5f
		};

		/*glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertecies), vertecies, GL_STATIC_DRAW);*/
		v_Buffer.reset(VertexBufferAbstraction::CreateVertexBuffer(vertecies, sizeof(vertecies)));
		/*idk y but the memory size needs to be passed in manually like bro what? - nvm i forgor sizeof only takes in the size of type, so it
		can't eval the entire thing. */

		BufferLayout buffers = {
			{"a_position", Shader::f3},
			{"color", Shader::f4}
		};

		BufferLayout layout(buffers);

		//uint32_t i = 0; 
		//for (Buffers& a : layout) {
		//	glEnableVertexAttribArray(i);
		//	glVertexAttribPointer(i, a.GetCount(a.shader), ShaderType(a.shader),
		//		a.normalized ? GL_TRUE : GL_FALSE, layout.stride,
		//		(const void*)a.offset);
		//	//sets size of each vertex upon reading generic array 
		//}
		auto l = layout.GetBuffers();
		for (int i = 0; i < l.size(); i++) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, l[i].GetCount(l[i].shader), ShaderType(l[i].shader), l[i].normalized ? GL_TRUE : GL_FALSE, layout.stride, (const void*)l[i].offset);
		}

		
		

		unsigned int indicies[3] = { 0, 1 ,2 };

		/*glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);*/
		i_Buffer.reset(IndexBufferAbstraction::CreateIndexBuffer(indicies, sizeof(indicies))); 

		std::string vectorShaders = R"(
			#version 330 core
			layout(location = 0) in vec3 a_position;

			out vec3 v_position; 

			void main(){
				v_position = a_position; 
				gl_Position = vec4(a_position, 1.0);
			}
		)";

		std::string fragmentShaders = R"(
			#version 330 core
			layout(location = 0) out vec4 color;

			in vec3 v_position;

			void main(){
				color = vec4(v_position + 0.5, 1.0); 
			}
		)";

		shader.reset(ShaderAbstraction::CreateShader(vectorShaders, fragmentShaders)); //not error
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

			glClear(GL_COLOR_BUFFER_BIT);

			shader->Bind();
			glBindVertexArray(vertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);



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