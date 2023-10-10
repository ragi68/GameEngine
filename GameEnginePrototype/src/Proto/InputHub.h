#include "EntryCore.h"

namespace Proto {
	class PROTO_API InputHub {
	public:
		inline static bool isKeyPressed(int keycode) { return input->isPressedFunction(keycode); }
		inline static bool isMousePressed(int button) { return input->isMousePressedFunction(button); }
		inline static std::pair<float, float> GetCursorPosition() { return input->CursorPosition();  }


	protected:
		virtual bool isPressedFunction(int keycode) = 0;
		virtual std::pair<float, float> CursorPosition() = 0;
		virtual bool isMousePressedFunction(int button) = 0;

	private: 
		static InputHub* input;

	};
}