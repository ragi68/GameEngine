#pragma once
#include "Proto/Window.h"
#include <GLFW/glfw3.h> 
namespace Proto{
	class WindowsApplication : public AbstractWin
	{
	public:
		WindowsApplication(const WindowSize& size);
		virtual ~WindowsApplication();


		void UpdateWindow() override; //allow base class override and set frame buffers

		inline unsigned int GetWidth() const override { return windowData.Width; }
		inline unsigned int GetHeight() const override { return windowData.Height; }

		//window attributes -> overridded from base class
		inline void EventCallBack(const EventCall& call) override { windowData.CallBack = call; }
		//callbacks are functions which are arguments in another function


		//use vsync features 
		void VSync(bool enabled) override;
		bool VSyncEnabled() const override; //define in windowsapplication.cpp

		inline void* GetWindowPointer() const { return window;  } //returns 

	private:
		virtual void Init(const WindowSize& size);
		virtual void Destroy();

	private:

		GLFWwindow* window;
		struct Data {
			std::string name1;
			unsigned int Width, Height;
			EventCall CallBack;
			bool vsync;


		};

		Data windowData;
	};
}

