#pragma once

#include "Event.h"

namespace dvg {
	class DVG_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x,float y) 
			: m_Mouse_X(x), m_Mouse_Y(y) {}

		inline float GetX() const { return m_Mouse_X;  }
		inline float GetY() const { return m_Mouse_Y;  }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_Mouse_X << ", " << m_Mouse_Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_Mouse_X, m_Mouse_Y;
	};

	class DVG_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset,float yOffset) 
			: m_Mouse_XOffset(xOffset), m_Mouse_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_Mouse_XOffset;  }
		inline float GetYOffset() const { return m_Mouse_YOffset;  }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_Mouse_XOffset << ", " << m_Mouse_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_Mouse_XOffset, m_Mouse_YOffset;
	};

	class DVG_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

			int m_Button;
	};

	class DVG_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	
	class DVG_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
