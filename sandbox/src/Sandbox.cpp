#include <dvigatel.h>

class ExampleLayer : public dvg::Layer {
public:
	ExampleLayer() : Layer("example") {}

	void OnUpdate() override {
		DVG_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(dvg::Event& event) override {
		DVG_TRACE("{0}", event);
	}
};

class Sandbox : public dvg::Application {
	public:
		Sandbox() {
			PushLayer(new ExampleLayer());
		}
		~Sandbox(){}
};


dvg::Application* dvg::CreateApplication() {
	return new Sandbox();
}
