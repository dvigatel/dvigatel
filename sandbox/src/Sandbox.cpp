#include <dvigatel.h>

class Sandbox : public dvg::Application {
	public:
		Sandbox() {}
		~Sandbox(){}
};


dvg::Application* dvg::CreateApplication() {
	return new Sandbox();
}
