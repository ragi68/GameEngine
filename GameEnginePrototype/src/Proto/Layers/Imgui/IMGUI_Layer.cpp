#include "PrecompiledHeaders.h"

//files needed
#include "Proto/Application.h"
#include "IMGUI_Layer.h"
 
//Render necessities
#define IMGUI_IMPL_API
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

//base render necessities
#include "glad/glad.h"
#include "GLFW/glfw3.h"



//adapted from example files of ImGui - all copy-pasted and slightly adpated for variable names from examples/opengl_glfw
namespace Proto {
	IMGUI_Layer::IMGUI_Layer() : LayerClass("GUI") {}

	IMGUI_Layer::~IMGUI_Layer() {

	}

	void IMGUI_Layer::OnStack() { //puts the layer onto stack and its functionalities onto stack as well. 

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		//ImGui::StyleColorsLight();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetRef().GetWindowPointer());
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");

	}


	//next two are also copied from opengl_glfw
	void IMGUI_Layer::OnPop() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void IMGUI_Layer::Render()
	{
		bool showDemoWindow = true;
		ImGui::ShowDemoWindow(&showDemoWindow);
	}
	 //mistake adding update funct. in this file; unpdate function conflicted with separate layer control functions and caused abort sequence to activate
	void IMGUI_Layer::Init_Layer() //tells app to start new layer - more controlled by lyaer than whole application
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	} //copied from examples/open_glfw

	void IMGUI_Layer::End_Layer() //renders application - copy from examples/opengl_gflw
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetRef().GetWidth(), app.GetRef().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
		m_time = time;

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}


	


}



