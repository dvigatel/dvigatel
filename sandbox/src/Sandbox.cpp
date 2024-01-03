#include <dvigatel.h>
#include "imgui/imgui.h"

class ExampleLayer : public dvg::Layer {
public:
	ExampleLayer() : Layer("example") { }

	void OnUpdate() override {
		if (dvg::Input::IsKeyPressed(DVG_KEY_TAB))
			DVG_TRACE("TAB KEY IS PRESSED");
	}

	virtual void OnImGuiRender() override {
	}

	void OnEvent(dvg::Event& event) override {
		// DVG_TRACE("{0}", event);
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
