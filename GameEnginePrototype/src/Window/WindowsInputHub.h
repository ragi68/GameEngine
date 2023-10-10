#pragma once

#include "Proto/InputHub.h"

namespace Proto {
	class WindowsInputHub : public InputHub {
	protected:
		virtual bool isPressedFunction(int keycode) override; 
		virtual std::pair<float, float> CursorPosition() override;
		virtual bool isMousePressedFunction(int button) override;
	};
}