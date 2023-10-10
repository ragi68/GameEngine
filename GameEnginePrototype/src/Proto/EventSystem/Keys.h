#pragma once

#include "EventHeader.h"


namespace Proto {
	//base key class -- includes keycode and debug feature
	class PROTO_API KeyStates : public Events { //gives if key is pressed or not - not to do anything imortant

	public:
		inline int GetKeyCode() const { return m_keycode; }
		EVENT_CATEGORY(EventKEY | EventINPUT)

	protected:
		KeyStates(int keycode)
			: m_keycode(keycode)  {}

		int m_keycode;
	};
	 //keypressed
	class PROTO_API KeyPressed : public KeyStates {
	public:
		KeyPressed(int keycode, int reps) 
			: KeyStates(keycode), m_repeats(reps) {}
		inline int GetReps() const { return m_repeats;}

		/*std::string toString() const override {
			std::stringstream ss;
			ss << "Key Pressed" << m_keycode << "\nRepeats: " << m_repeats;
			return ss.str();
		}*/

		EVENT_TYPE(KeyPressed);
	protected:
		int m_repeats;
	};
	//key-release
	class PROTO_API KeyRelease :public KeyStates {
	public:
		KeyRelease(int keycode) : KeyStates(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			//ss << "Key Released";
			return ss.str();
		}

		EVENT_TYPE(ReleaseKey);

	protected:
		int m_repeats;
	};
}

