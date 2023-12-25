#pragma once

#ifdef DVG_PLATFORM_WINDOWS
extern dvg::Application* dvg::CreateApplication();

int main(int argc, char **argv) {
	auto app = dvg::CreateApplication();
	app->Run();
	delete app;
}

#endif
