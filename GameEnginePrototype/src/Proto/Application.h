#pragma once
#include "EntryCore.h"
#include "Window.h"
#include "Stackable.h"
#include "EventSystem/EventHeader.h"
#include "Layers/Imgui/IMGUI_Layer.h"
#include "Proto/EventSystem/AppEvent.h"
#include "RenderAPI/ShaderAbstraction.h"
#include "RenderAPI/VertexBufferAbstraction.h"
#include "RenderAPI/IndexBufferAbstraction.h"

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
		std::unique_ptr<AbstractWin> window;
		std::unique_ptr<ShaderAbstraction> shader;
		std::unique_ptr<VertexBufferAbstraction> v_Buffer;
		std::unique_ptr<IndexBufferAbstraction> i_Buffer;

		IMGUI_Layer* imguiLayer; 
		bool running = true;
		Stackable layer_stack;
		static Application* s_Instance;

		unsigned int vertexArray; 
	};


	Application* StartUp();
}
