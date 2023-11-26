#pragma once
#include "EntryCore.h"
#include "Window.h"
#include "Stackable.h"
#include "EventSystem/EventHeader.h"
#include "Layers/Imgui/IMGUI_Layer.h"
#include "Proto/EventSystem/AppEvent.h"
#include "Camera/Cameras.h"
#include "RendererHeaders.h"

#include "InputModule.h"
#include "KeyCodes.h"


namespace Proto {
	class PROTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void RunApp();

		void Event(Events& e);

		inline static Application& Get() {
			return *s_Instance;
		}

		//layer push/pop
		void PushLayer(LayerClass* layer);
		void PushBelowLayer(LayerClass* layer);

		inline AbstractWin& GetRef() {
			return *window;
		}

	private:
		bool WindowClose(CloseWindow& event);
		std::shared_ptr<AbstractWin> window;
		std::shared_ptr<ShaderAbstraction> shader;
		std::shared_ptr<VertexBufferAbstraction> v_Buffer;
		std::shared_ptr<IndexBufferAbstraction> i_Buffer;
		std::shared_ptr<VertexArrayAbstraction> v_Array; 
		std::shared_ptr<RenderAbstraction> renderer;
		std::unique_ptr<InputModule> input;

		Camera3D camera;

		IMGUI_Layer* imguiLayer; 
		bool running = true;
		Stackable layer_stack;
		static Application* s_Instance;

	};


	Application* StartUp();
}
