#include "PrecompiledHeaders.h"
#include "IMGUI_Layer.h"
#include "OpenGLImplementation/imgui_impl_opengl3.h"
#include "GLFW//glfw3.h"
#include "Proto/Application.h"
#include "Proto/EventSystem/EventHeader.h"
#include "glad/glad.h"

//adapted from example files of ImGui
namespace Proto{
	IMGUI_Layer::IMGUI_Layer() : LayerClass("GUI") {}

	IMGUI_Layer::~IMGUI_Layer(){

	}

	void IMGUI_Layer::OnEvent(Events& e) { //sends events collected through the dispatcher
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<MouseDown>(Bind_Key(IMGUI_Layer::OnMouseDown));
		dispatcher.dispatch<MouseUp>(Bind_Key(IMGUI_Layer::OnMouseUp));
		dispatcher.dispatch<KeyPressed>(Bind_Key(IMGUI_Layer::OnKeyPressed));
		dispatcher.dispatch<MouseMoved>(Bind_Key(IMGUI_Layer::OnMouseMove));
		dispatcher.dispatch<KeyRelease>(Bind_Key(IMGUI_Layer::OnKeyReleased));
		dispatcher.dispatch<MouseScroll>(Bind_Key(IMGUI_Layer::OnMouseScroll));
		dispatcher.dispatch<CloseWindow>(Bind_Key(IMGUI_Layer::OnWindowClose));
		dispatcher.dispatch<WindowResize>(Bind_Key(IMGUI_Layer::OnWindowResize));

	}

	void IMGUI_Layer::Update() {
		

		ImGuiIO& io = ImGui::GetIO(); 
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetRef().GetWidth(), app.GetRef().GetHeight()); 

		float time = (float)glfwGetTime();
		io.DeltaTime = time > 0.0f? (time - m_time) : (1.0f / 60.0f); 
		m_time = time; 

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool open = true;
		ImGui::ShowDemoWindow(&open); 

		ImGui::Render();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); 

	}

	void IMGUI_Layer::OnPop() {

	}

	void IMGUI_Layer::OnRender()
	{
	}

	void IMGUI_Layer::OnStack() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors; 
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_B] = GLFW_KEY_B;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_D] = GLFW_KEY_D;
		io.KeyMap[ImGuiKey_E] = GLFW_KEY_E;
		io.KeyMap[ImGuiKey_F] = GLFW_KEY_F;
		io.KeyMap[ImGuiKey_G] = GLFW_KEY_G;
		io.KeyMap[ImGuiKey_H] = GLFW_KEY_H;
		io.KeyMap[ImGuiKey_I] = GLFW_KEY_I;
		io.KeyMap[ImGuiKey_J] = GLFW_KEY_J;
		io.KeyMap[ImGuiKey_K] = GLFW_KEY_K;
		io.KeyMap[ImGuiKey_L] = GLFW_KEY_L;
		io.KeyMap[ImGuiKey_M] = GLFW_KEY_M;
		io.KeyMap[ImGuiKey_N] = GLFW_KEY_N;
		io.KeyMap[ImGuiKey_O] = GLFW_KEY_O;
		io.KeyMap[ImGuiKey_P] = GLFW_KEY_P;
		io.KeyMap[ImGuiKey_Q] = GLFW_KEY_Q;
		io.KeyMap[ImGuiKey_R] = GLFW_KEY_R;
		io.KeyMap[ImGuiKey_S] = GLFW_KEY_S;
		io.KeyMap[ImGuiKey_T] = GLFW_KEY_T;
		io.KeyMap[ImGuiKey_U] = GLFW_KEY_U;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_W] = GLFW_KEY_W;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;

		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;


		ImGui_ImplOpenGL3_Init("#version 410");

	}

	bool IMGUI_Layer::OnMouseDown(MouseDown& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetButton()] = true;

		return false;
	}
	bool IMGUI_Layer::OnMouseUp(MouseUp& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetButton()] = false;

		return false;
	}
	bool IMGUI_Layer::OnKeyPressed(KeyPressed& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true; //sets the keycode keydown to true and stops function
		return false;

	}
	bool IMGUI_Layer::OnKeyReleased(KeyRelease& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false; //sets keydown to false for key
		return false;
	}
	bool IMGUI_Layer::OnMouseMove(MouseMoved& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY()); //sets mouse pos to the mouse pso
		return false;
	}
	bool IMGUI_Layer::OnMouseScroll(MouseScroll& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel = e.getXOffset();//set scroll wheel yo x-offset
		io.MouseWheel += e.getYOffset(); //sets scroll whell to y-offset
		return false;
	}
	bool IMGUI_Layer::OnWindowClose(CloseWindow& e) {

		return false;
	}
	bool IMGUI_Layer::OnWindowResize(WindowResize& e) {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());//sets display width and height
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight()); //sets width/height while keeping evertyhing else the same(Affine transformation)
		return false;
	}



}

