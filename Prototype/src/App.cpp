#include "ProtoHeader.h"

#include <GLM/glm/gtc/type_ptr.hpp>
#include "ImGui/imgui.h"
class FirstLayer : public Proto::LayerClass {
public:
	FirstLayer(): camera(glm::radians(90.0f), 16.0f / 9.0f, 0.0001f, 100.0f) {

		renderer.reset(Proto::RenderAbstraction::CreateRenderer());

		

		

		float vertecies[4 * 7] = { //remember that the z-axis is flipped for our camera. also keep auto camera nera plane value as close to zero as possible. 
			-2.0f, -2.0f, -1.0f, 0.6f, 0.23f, 0.19f, 1,
			-2.0f, 2.0f, -3.0f, 0.8f, 0.9f, 0.35f, 1,
			0.0f, 1.0f, -5.0f, 0.25f, 0.6f, 0.7f, 1,
			0.0f, -1.0f, 2.0f, 0.6f, 0.7f, 0.8f, 1
		};

		Proto::BufferLayout buffers = {
			{"a_position", Proto::Shader::f3},
			{"a_color", Proto::Shader::f4}
		};



		v_Array.reset(Proto::VertexArrayAbstraction::CreateVertexArray());
		v_Buffer.reset(Proto::VertexBufferAbstraction::CreateVertexBuffer(vertecies, sizeof(vertecies)));	
		v_Buffer->SetBufferLayout(buffers);//needed to make sure the addvertexBuffer function works; else nothing happens
		v_Array->AddVertexBuffer(v_Buffer);
		unsigned int indicies[6] = { 0, 1 ,2, 2, 3, 0 };
		i_Buffer.reset(Proto::IndexBufferAbstraction::CreateIndexBuffer(indicies, sizeof(indicies)));
		v_Array->AddIndexBuffer(i_Buffer);
		std::string vectorShaders = R"(
			#version 330 core
			layout(location = 0) in vec3 a_position;
			layout(location = 1) in vec4 a_color; 

			uniform mat4 v_matrix; 
			uniform mat4 transform;

			out vec3 v_position; 
			out vec4 v_color;


			void main(){
				v_position = a_position; 
				v_color = a_color;
				gl_Position = v_matrix * transform * vec4(a_position, 1.0); 
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
		shader.reset(Proto::ShaderAbstraction::CreateShader(vectorShaders, fragmentShaders));



		Proto::BufferLayout buffer = {
			{"a_position", Proto::Shader::f3},
		};

		float flatArr[4 * 3] = {
			-1.0f, -1.0f, 0.0f,
			-1.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			1.0f, -1.0f, 0.0f
		};
		unsigned int indice[6] = { 0, 1,2, 2, 3, 0 };

		v_array_flat.reset(Proto::VertexArrayAbstraction::CreateVertexArray());
		v_buffer_flat.reset(Proto::VertexBufferAbstraction::CreateVertexBuffer(flatArr, sizeof(flatArr)));
		v_buffer_flat->SetBufferLayout(buffer);
		v_array_flat->AddVertexBuffer(v_buffer_flat);
		i_buffer_flat.reset(Proto::IndexBufferAbstraction::CreateIndexBuffer(indice, sizeof(indice)));
		v_array_flat->AddIndexBuffer(i_buffer_flat);

		std::string vectorFlatShaders = R"(
			#version 330 core
			layout(location = 0) in vec3 a_position;


			uniform mat4 v_matrix; 
			uniform mat4 transform;

			out vec3 v_position; 


			void main(){
				v_position = a_position; 
				gl_Position = v_matrix * transform * vec4(a_position, 1.0); 
			}
		)";
		std::string fragmentFlatShaders = R"(
			#version 330 core
			layout(location = 0) out vec4 color;

			uniform vec3 flat_color;

			in vec3 v_position;


			void main(){
				color = vec4(flat_color, 1.0f);
			}
		)";

		shader_flat.reset(Proto::ShaderAbstraction::CreateShader(vectorFlatShaders, fragmentFlatShaders)); 
		 
	}

	virtual void Render() override
	{
		ImGui::Begin("Color Pick");
		ImGui::ColorEdit3("Color Pick", glm::value_ptr(flatColor));
		ImGui::End();

	}

	void Update() override {
		renderer->ClearWindow();

		Proto::Time t = t.getFrameTime();
		float ts = t.getTime() - pastTime;
		pastTime = t.getTime();
		
		if (input->checkPressed(KEY_I)) {
			objectPos.y += 5.0f * ts;
		}
		camera.SetPosition(position);
		camera.SetRotation(rotation);
		
		shader_flat->Bind();
		shader_flat->BindFloat3Data("flat_color", flatColor);

		
		glm::mat4 tf = glm::translate(glm::mat4(1.0f), objectPos);
		renderer->DrawAndEnd(v_Array, tf, shader, camera);
		renderer->DrawAndEnd(v_array_flat, glm::mat4(1.0f), shader_flat, camera);
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

	std::shared_ptr<Proto::ShaderAbstraction> shader_flat;
	std::shared_ptr<Proto::VertexArrayAbstraction> v_array_flat;
	std::shared_ptr<Proto::VertexBufferAbstraction> v_buffer_flat;
	std::shared_ptr<Proto::IndexBufferAbstraction> i_buffer_flat;

	std::shared_ptr<Proto::RenderAbstraction> renderer;
	std::unique_ptr<Proto::InputModule> input;

	

	Proto::Camera3D camera;


	glm::vec3 position = { 0.0f, 0.0f, 5.0f };
	glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
	float pastTime = 0.0f;
	float frameTime = 0.0f;

	glm::vec3 objectPos = { 1.0f, 1.0f, 1.0f };

	glm::vec3 flatColor = { 0.5f, 0.2f, 0.34f };
	

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