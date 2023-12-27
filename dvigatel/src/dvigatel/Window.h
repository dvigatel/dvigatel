#pragma once
#include "dvgpch.h"

#include "dvigatel/Core.h"
#include "dvigatel/Events/Event.h"

namespace dvg {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string &title = "dvigatel",
			unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class DVG_API Window {
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
