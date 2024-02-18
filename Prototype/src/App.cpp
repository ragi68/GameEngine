#include "ProtoHeader.h"

#include <GLM/glm/gtc/type_ptr.hpp>
#include "ImGui/imgui.h"
class FirstLayer : public Proto::LayerClass {
public:
	FirstLayer() : camera(glm::radians(90.0f), 16.0f / 9.0f, 0.0001f, 100.0f) {

		renderer.reset(Proto::RenderAbstraction::CreateRenderer());





		float vertecies[4 * 6] = { //remember that the z-axis is flipped for our camera. also keep auto camera nera plane value as close to zero as possible. 
			-2.0f, -2.0f, -1.0f, 0.6f, 0.23f, 0.19f, 
			-2.0f, 2.0f, -3.0f, 0.8f, 0.9f, 0.35f, 
			0.0f, 1.0f, -5.0f, 0.25f, 0.6f, 0.7f, 
			0.0f, -1.0f, 2.0f, 0.6f, 0.7f, 0.8f
		};

		Proto::BufferLayout buffers = {
			{"a_position", Proto::Shader::f3},
			{"a_color", Proto::Shader::f3}
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
			layout(location = 1) in vec3 a_color; 

			uniform mat4 v_matrix; 
			uniform mat4 transform;

			out vec3 v_position; 
			out vec3 v_color;


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
			in vec3 v_color; 

			void main(){
				color = vec4(v_color, 1.0);
			}
		)";
		shader.reset(Proto::ShaderAbstraction::CreateShader(vectorShaders, fragmentShaders));



		Proto::BufferLayout buffer = {
			{"a_position", Proto::Shader::f3},
			{"a_color", Proto::Shader::f2}
		};

		float flatArr[4 * 5] = {
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f, 0.0f
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
		//why is a-color not taking in vec2
		std::string textureVectors = R"(
			#version 330 core
			layout(location = 0) in vec3 a_position;
			layout(location = 1) in vec2 a_color;

			uniform mat4 v_matrix;
			uniform mat4 transform;
			
			out vec2 v_color;

			void main(){
				v_color = a_color;
				gl_Position = v_matrix * transform * vec4(a_position, 1.0); 
			}


		
		)";

		std::string textureFragment = R"(
			#version 330 core
			layout(location = 0) out vec4 color;

			
			in vec2 v_color;

			uniform sampler2D test_texture;
			vec4 texture_color;

			void main(){
				color = texture(test_texture, v_color);
				
			}
		)";



		shader_texture.reset(Proto::ShaderAbstraction::CreateShader(textureVectors, textureFragment));

		//texture2D =  Proto::Texture2D::CreateTexture("TestAssets/Cat.jpg"); abstract texture2D -> texture and make it a separate function
		texture2D.reset(Proto::Texture2D::Create2DTexture("TestAssets/TestTexture.jpg"));
		texture2D_2.reset(Proto::Texture2D::Create2DTexture("TestAssets/Cat-removebg-preview.png"));



		shader_texture->Bind();
		shader_texture->BindIntData("test_texture", 0);

		
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

		if (input->checkPressed(KEY_W)) {
			position.y += 5.0f * ts;
		}
		if (input->checkPressed(KEY_A)) {
			position.x -= 5.0f * ts;
		}
		if (input->checkPressed(KEY_S)) {
			position.y -= 5.0f * ts;
		}
		if (input->checkPressed(KEY_D)) {
			position.x += 5.0f * ts;
		}
		if (input->checkPressed(KEY_E)) {
			rotation.x += 5.0f * ts;
		}
		if (input->checkPressed(KEY_R)) {
			rotation.y += 5.0f * ts;
		}
		if (input->checkPressed(KEY_Z)) {
			position.z += 5.0f * ts;
		}
		if (input->checkPressed(KEY_X)) {
			position.z -= 5.0f * ts;
		}
		camera.SetPosition(position);
		camera.SetRotation(rotation);

		shader_flat->Bind();
		shader_flat->BindFloat3Data("flat_color", flatColor);


		glm::mat4 tf = glm::translate(glm::mat4(1.0f), objectPos);
		//renderer->DrawAndEnd(v_Array, tf, shader, camera);
		texture2D->Bind();

		renderer->DrawAndEnd(v_array_flat, tf, shader_texture, camera);

		texture2D_2->Bind(); 
	 	renderer->DrawAndEnd(v_array_flat, tf, shader_texture, camera); //got smthng for blending - fix goofy ahh light issue. 

		err.reset(Proto::Error::SeeError());
		err->GetErrors();

		
	}

	void OnEvent(Proto::Events& e) override {
		if (e.GetEvent() == Proto::EventTypes::KeyPressed) {
			Proto::KeyPressed& e2 = (Proto::KeyPressed&)e;
		}
	}

private:
	std::shared_ptr<Proto::ShaderAbstraction> shader, shader_flat, shader_texture;
	std::shared_ptr<Proto::VertexBufferAbstraction> v_Buffer, v_buffer_flat;
	std::shared_ptr<Proto::IndexBufferAbstraction> i_Buffer, i_buffer_flat;
	std::shared_ptr<Proto::VertexArrayAbstraction> v_Array, v_array_flat;
	std::shared_ptr<Proto::Texture2D> texture2D;
	std::shared_ptr<Proto::Texture2D> texture2D_2;


	std::shared_ptr<Proto::RenderAbstraction> renderer;
	std::unique_ptr<Proto::InputModule> input;

	std::unique_ptr<Proto::Error> err;



	Proto::Camera3D camera;


	glm::vec3 position = { 0.0f, 0.0f, 2.0f };
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