#include <dvigatel.h>
#include "imgui/imgui.h"

class ExampleLayer : public dvg::Layer {
public:
	ExampleLayer() : Layer("example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f) {
		m_VertexArray.reset(dvg::VertexArray::Create());

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f,
		};
		std::shared_ptr<dvg::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(dvg::VertexBuffer::Create(vertices, sizeof(vertices)));
		dvg::BufferLayout layout = {
			{ dvg::ShaderDataType::Float3, "a_Position" },
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);
		
		unsigned int indices[3] = { 0,1,2 };
		std::shared_ptr<dvg::IndexBuffer> indexBuffer;
		indexBuffer.reset(dvg::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSRC = R"(
			#version 330 core

			uniform mat4 u_ViewProjection;
			
			layout(location = 0) in vec3 a_Position;	
			out vec3 v_Position;
			void main() {
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSRC = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;	
			in vec3 v_Position;
			void main() {
				color = vec4(v_Position + 0.5, 1.0);
			}
		)";

		m_Shader = std::make_unique<dvg::Shader>(vertexSRC, fragmentSRC);
	}

	void OnUpdate() override {
		if (dvg::Input::IsKeyPressed(DVG_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed;
		else if (dvg::Input::IsKeyPressed(DVG_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed;
		if (dvg::Input::IsKeyPressed(DVG_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed;
		else if (dvg::Input::IsKeyPressed(DVG_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed;

		if (dvg::Input::IsKeyPressed(DVG_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed;
		if (dvg::Input::IsKeyPressed(DVG_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed;

		dvg::RenderCommand::SetClearColor({ 0.1f,0.1f,0.1f,1 });
		dvg::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);
	
		dvg::Renderer::BeginScene(m_Camera);
		dvg::Renderer::Submit(m_VertexArray, m_Shader);
		dvg::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override {
	}

	void OnEvent(dvg::Event& event) override {
	}

private:
	std::shared_ptr<dvg::Shader> m_Shader;
	std::shared_ptr<dvg::VertexArray> m_VertexArray;
	dvg::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	
	float m_CameraMoveSpeed= 0.1f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 2.0f;
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
