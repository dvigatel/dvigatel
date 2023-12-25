#pragma once

#ifdef DVG_PLATFORM_WINDOWS
extern dvg::Application* dvg::CreateApplication();

int main(int argc, char **argv) {
	dvg::Log::Init();
	DVG_CORE_WARN("INITIALIZED");
	int a = 5;
	DVG_INFO("Hello, Var={0}", a);

	auto app = dvg::CreateApplication();
	app->Run();
	delete app;
}

#endif
