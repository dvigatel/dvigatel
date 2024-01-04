#pragma once

#include "Core.h"
#include "Events/Event.h"

#include "Window.h"
#include "dvigatel/LayerStack.h"
#include "dvigatel/Events/Event.h"
#include "dvigatel/Events/ApplicationEvent.h"

#include "dvigatel/ImGui/ImGuiLayer.h"

#include "dvigatel/Renderer/Shader.h"

namespace dvg {

	class DVG_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
		inline Window& GetWindow() { return *m_Window;  }

		inline static Application& Get() { return *s_Instance;  }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	// to be defined in a client
	Application* CreateApplication();
}