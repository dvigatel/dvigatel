#include "Application.h"

#include "dvigatel/Events/ApplicationEvent.h"
#include "dvigatel/Log.h"

namespace dvg {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			DVG_TRACE(e);
		}
		while (true);
	}
}