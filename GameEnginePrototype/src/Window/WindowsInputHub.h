#pragma once
#include "PrecompiledHeaders.h"
#include "Proto/InputHub.h"

namespace Proto {
	class WindowsInputHub : public InputHub {
	protected:
		virtual bool isPressedFunction(int keycode) override; 
	};
}