#pragma once
#include "EntryCore.h"
#include <utility>

namespace Proto {
	class InputModule {
	public:

		bool checkPressed(int key);
		bool checkMousePressed(int button);
		std::pair<float, float> GetCursorPosition();

	
	};
}