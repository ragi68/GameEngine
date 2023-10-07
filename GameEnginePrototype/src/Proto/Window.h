#pragma once
#include "PrecompiledHeaders.h"
#include "EntryCore.h"
#include "Proto/EventSystem/EventHeader.h"

namespace Proto {
	//gives window size data -- use class later? Interchangeable, anyways for our purposes. -> public WindowSize
	struct WindowSize {

		unsigned int width;
		unsigned int height;
		
		WindowSize(int w = 1280, int h = 720) : width(w), height(h) {}
	};

	class PROTO_API AbstractWin { //create abstract window -> size and name(fixed??), window tick update, rendering with openGL, window vsync to maximize framerate??
	public:

		using EventCall = std::function<void(Events&)>; //creates a 'function' of void that takes in event reference
															//|
															//|
		//constructors.												//|
		AbstractWin() {}											//|
															//|
		virtual ~AbstractWin() {}										//|
															//|
		//is what it says											//|
		virtual void UpdateWindow() = 0;									//|
															//|
		//debug stuff												//|
		virtual unsigned int GetWidth() const = 0;								//|
		virtual unsigned int GetHeight() const = 0;								//|
															//|
															//|
		//gets events done to											//|
		virtual void EventCallBack(const EventCall& call) = 0; //makes a function to collect events dispatched to window layer. 
		//sets vsync for window framerate optimization
		virtual void VSync(bool enable) = 0;
		virtual bool VSyncEnabled() const = 0;
		virtual void* GetWindowPointer() const = 0; 
		static AbstractWin* windowGenerator(const WindowSize& size = WindowSize());//createwindow is a pre-defined macro with nodef, so it cannot find it. 


	};
	
}
