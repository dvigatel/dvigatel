#pragma once

#include "dvigatel/Renderer/RendererAPI.h"

namespace dvg {

	class OpenGLRendererAPI : public RendererAPI {

		virtual void Clear() override;
		virtual void SetClearColor(const glm::vec4& color) override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;

	};

}
