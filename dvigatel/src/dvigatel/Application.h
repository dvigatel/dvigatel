#pragma once

#include "Core.h"
#include "Events/Event.h"

#include "Window.h"
#include "dvigatel/LayerStack.h"
#include "dvigatel/Events/Event.h"
#include "dvigatel/Events/ApplicationEvent.h"

namespace dvg {

	class DVG_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// to be defined in a client
	Application* CreateApplication();
}