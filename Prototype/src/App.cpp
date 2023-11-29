#include "ProtoHeader.h"


class FirstLayer : public Proto::LayerClass {
public:
	FirstLayer(): camera(glm::radians(90.0f), 16.0f / 9.0f, 0.0001f, 100.0f) {

		renderer.reset(Proto::RenderAbstraction::CreateRenderer());

		v_Array.reset(Proto::VertexArrayAbstraction::CreateVertexArray());



		float vertecies[4 * 7] = { //remember that the z-axis is flipped for our camera. also keep auto camera nera plane value as close to zero as possible. 
			-2.0f, -2.0f, -1.0f, 0.6f, 0.23f, 0.19f, 1,
			2.0f, -2.0f, -3.0f, 0.8f, 0.9f, 0.35f, 1,
			0.0f, 1.0f, -5.0f, 0.25f, 0.6f, 0.7f, 1,
			0.0f, -1.0f, 2.0f, 0.6f, 0.7f, 0.8f, 1
		};


		v_Buffer.reset(Proto::VertexBufferAbstraction::CreateVertexBuffer(vertecies, sizeof(vertecies)));
		/*idk y but the memory size needs to be passed in manually like bro what? - nvm i forgor sizeof only takes in the size of type, so it
		can't eval the entire thing. */

		Proto::BufferLayout buffers = {
			{"a_position", Proto::Shader::f3},
			{"a_color", Proto::Shader::f4}
		};

		Proto::BufferLayout layout(buffers);
		v_Buffer->SetBufferLayout(layout);//needed to make sure the addvertexBuffer function works; else nothing happens


		v_Array->AddVertexBuffer(v_Buffer);




		unsigned int indicies[6] = { 0, 1 ,2, 2, 3, 0 };

		i_Buffer.reset(Proto::IndexBufferAbstraction::CreateIndexBuffer(indicies, sizeof(indicies)));
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
				gl_Position = v_matrix * vec4(a_position, 1); 
			}
		)"; //4th coordinate in glPosition is the 'scale'. The lower the value, the more zoomed in the iamge will be. 

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

		shader.reset(Proto::ShaderAbstraction::CreateShader(vectorShaders, fragmentShaders));
	}
	void Update() override {
		renderer->ClearWindow();

		if (input->checkPressed(KEY_Q)) {
			position.z += 0.2f;
		}
		else if (input->checkPressed(KEY_E)) {
			position.z -= 0.2f;
		}

		if (input->checkPressed(KEY_W)) {
			position.y += 0.2f;
		}
		else if (input->checkPressed(KEY_S)) {
			position.y -= 0.2f;
		}

		if (input->checkPressed(KEY_D)) {
			position.x += 0.2f;
		}
		else if (input->checkPressed(KEY_A)) {
			position.x -= 0.2f;
		}

		if (input->checkPressed(KEY_LEFT)) {
			rotation.y += 0.1f;
		}
		else if (input->checkPressed(KEY_RIGHT)) {
			rotation.y -= 0.1f;
		}

		if (input->checkPressed(KEY_UP)) {
			rotation.z += 0.1f;
		}
		else if (input->checkPressed(KEY_DOWN)) {
			rotation.z -= 0.1f;
		}

		if (input->checkPressed(KEY_Z)) {
			rotation.x += 0.1f;
		}
		else if (input->checkPressed(KEY_X)) {
			rotation.x -= 0.1f;
		}


		camera.SetPosition(position);
		camera.SetRotation(rotation);

		shader->Bind();
		v_Array->Bind();

		shader->BindMatrixData("v_matrix", camera.GetVPMatrix()); //camera.GetVPMatrix(); 

		renderer->DrawAndEnd(v_Array, 3.4f);
	}

	void OnEvent(Proto::Events& e) override{
		if (e.GetEvent() == Proto::EventTypes::KeyPressed) {
			Proto::KeyPressed& e2 = (Proto::KeyPressed&)e;
		}

	}

private:
	std::shared_ptr<Proto::ShaderAbstraction> shader;
	std::shared_ptr<Proto::VertexBufferAbstraction> v_Buffer;
	std::shared_ptr<Proto::IndexBufferAbstraction> i_Buffer;
	std::shared_ptr<Proto::VertexArrayAbstraction> v_Array;
	std::shared_ptr<Proto::RenderAbstraction> renderer;
	std::unique_ptr<Proto::InputModule> input;

	Proto::Camera3D camera;

	glm::vec3 position = { 0.0f, 0.0f, 10.0f };
	glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };

	

};


class ProtoType : public Proto::Application {
public:
	ProtoType() {
		PushLayer(new FirstLayer()); 

	}

	~ProtoType() {

	}
};


Proto::Application* Proto::StartUp() {
	return new ProtoType();
}