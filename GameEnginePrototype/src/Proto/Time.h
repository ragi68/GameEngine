#pragma once

namespace Proto {
	class Time {
	public: 
		Time(float time) : time(time){ }
		Time() = default; 
		float getFrameTime();

		float getTime() {return time;}

		float time; 
	};
}