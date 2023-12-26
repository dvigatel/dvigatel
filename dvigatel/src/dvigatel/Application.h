#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace dvg {

	class DVG_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in a client
	Application* CreateApplication();
}