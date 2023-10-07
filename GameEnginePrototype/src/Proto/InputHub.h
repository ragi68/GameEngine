#include "EntryCore.h"

namespace Proto {
	class PROTO_API InputHub {
	public:
		static bool isKeyPressed(int keycode) { return inputINST->isPressedFunction(keycode); }

	protected:
		virtual bool isPressedFunction(int keycode) = 0;
		static InputHub* inputINST;

	};
}