#pragma once

namespace Proto {
	class Time {
	public: 
		float getFrameTime();
		void CalculateFrameTime(float framerate, float frametime);
	};
}