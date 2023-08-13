#pragma once

#include "EventHeader.h"




namespace Proto {
	class PROTO_API MouseMoved : public Events {//gives x-y of mouse
	public:
		MouseMoved(float x, float y) : 
			m_X(x), m_Y(y) {}

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }
		/*std::string toString() const override {
			std::stringstream ss;
			ss << "corods: " << m_X << ", " << m_Y;
			return ss.str();
		}*/
		EVENT_TYPE(MouseMove);
		EVENT_CATEGORY(EventMOUSE | EventINPUT);
	private: 
		float m_X, m_Y;
	};

	class PROTO_API MouseScroll : public Events { //gives potential offset given by a scroll -> MoveWindow() -> inherits from mousescroll or use friend?
	public: 
		MouseScroll(float x_offset, float y_offset) : 
			m_xOffset(x_offset), m_yOffset(y_offset) {}

		inline float getXOffset() const { return m_xOffset;  }
		inline float getYOffset() const { return m_yOffset;  }

		std::string toString() const override {
			std::stringstream ss;
			ss << "Offset" << m_xOffset << ", " << m_yOffset;
			return ss.str();
		}

		EVENT_TYPE(MouseScroll);
		EVENT_CATEGORY(EventMOUSE | EventINPUT);
	private: 
		float m_xOffset, m_yOffset;
	};

	class PROTO_API MouseClick : public Events {
	public: 
		inline int GetButton() const { return  m_ButtonNum;  }

		EVENT_CATEGORY(EventMOUSE | EventINPUT);

	protected:
		MouseClick(int click) :
			m_ButtonNum(click) {}
		int m_ButtonNum;
	};

	class PROTO_API MouseDown : public MouseClick {
	public:
		MouseDown(int click) : MouseClick(click) {}

		std::string toString() const override{
			std::stringstream ss;
			ss << "Clicks Done: " << m_ButtonNum;
			return ss.str();
		}

		EVENT_TYPE(MouseDown);
	};

	class PROTO_API MouseUp : public MouseClick {
	public:
		MouseUp(int click) : MouseClick(click) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "Clicks Done: " << m_ButtonNum;
			return ss.str();
		}

		EVENT_TYPE(MouseUp);
	};

	
	
}