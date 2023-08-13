#pragma once

#include "Proto/EntryCore.h"
#include "PrecompiledHeaders.h"


namespace Proto {
#define Bind_Key(fn) std::bind(&fn, this, std::placeholders::_1)
	//all event types to use
	enum class EventTypes {
		no = 0, 
		CloseWindow, ResizeWindow, FocusWindow, NoFocusWindow, MoveWindow, 
		Ticks, Update, Render, 
		KeyPressed, ReleaseKey, 
		MouseDown, MouseUp, MouseMove, MouseScroll
	}; 

	//used to broadly categorize what type of input
	enum EventCategories {
		no = 0, 
		EventAPP = BIT(0), 
		EventINPUT = BIT(1), 
		EventKEY = BIT(2), 
		EventMOUSE = BIT(3), 
		EventMOUSEDOWN = BIT(4)
	};
//virtuals to override in inherited classes -- a macro to be reused. has debug features. 
#define EVENT_TYPE(type) static EventTypes GetStaticType() { return EventTypes::##type; } virtual EventTypes GetEvent() const override { return GetStaticType(); } virtual const char* GetName() const override { return #type; } 
	//adding the override in makes it so that the compiler thinks we are overriding it from the base class... but we aren't?

//similar to the last one, but for categories
#define EVENT_CATEGORY(category) virtual int GetFlags() const override {return category;} //no base class?

	class PROTO_API Events {
		friend class EventDispatcher; //friend classes can see private/protected members of other classes. 
	public:
		virtual EventTypes GetEvent() const = 0; //get event type
		virtual const char* GetName() const = 0; //name of events to be overrided 
		virtual int GetFlags() const = 0; 
		virtual std::string toString() const { return GetName(); } //debug only
		//giving error on the virtual
		inline bool inCategory(EventCategories category) {
			return GetFlags() & category;
		}

		bool m_handled = false;

	};

	class EventDispatcher {
		template<typename T> //generic function
		using eventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Events& event) //referencer to an event and assigns it
			: m_event(event) {}
		

	template<typename T>
	bool dispatch(eventFn<T> f) { //need to add in template for event-specific action
		if (m_event.GetEvent() == T::GetStaticType()) { //if event type is equal to the current event in our list, then make the function 'handled' and true
			m_event.m_handled = f(*(T*)&m_event);
			return true;
		}
		return false; 
	}

	protected:
		Events& m_event;
	};

	inline std::ostream& operator<<(std::ostream& output, const Events& e) {
		return output << e.toString(); //return output of the event. 
	}
}