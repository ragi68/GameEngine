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

	class PROTO_API AbstractWin {
	public:

		//constructors. 
		AbstractWin() {}
	
		virtual ~AbstractWin() {}

		//is what it says
		virtual void UpdateWindow() const = 0;

		//debug stuff
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
	};
	
}