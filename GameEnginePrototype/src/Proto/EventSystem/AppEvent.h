#pragma once

#include "EventHeader.h"



namespace Proto {
	
	class PROTO_API WindowResize : public Events {
	public:
		WindowResize(unsigned int width, unsigned int height) 
			: m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const {return m_width; }
		inline unsigned int GetHeight() const{ return m_height; }

		/*std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResize: " << m_width << "x" << m_height;
			return ss.str();
		}*/

		EVENT_TYPE(ResizeWindow)
		EVENT_CATEGORY(EventAPP)
	private:
		unsigned int m_width, m_height;
	};

	class PROTO_API CloseWindow : public Events {
	public: 
		CloseWindow() {}
		EVENT_TYPE(CloseWindow)
		EVENT_CATEGORY(EventAPP)
	};

	class PROTO_API TickEvent : public Events {
	public:
		TickEvent() {}

		EVENT_TYPE(Ticks)
		EVENT_CATEGORY(EventAPP)
	};

	class PROTO_API UpdateEvent : public Events {
	public:
		UpdateEvent() {}

		EVENT_TYPE(Update)
		EVENT_CATEGORY(EventAPP)
	};

	class PROTO_API RenderEvent : public Events {
	public:
		RenderEvent() {}

		EVENT_TYPE(Render)
		EVENT_CATEGORY(EventAPP)
	}; 
}
