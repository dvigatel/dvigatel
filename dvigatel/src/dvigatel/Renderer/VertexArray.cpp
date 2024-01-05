#include "dvgpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "platform/OpenGL/OpenGLVertexArray.h"

namespace dvg {
	VertexArray* VertexArray::Create() {
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None: DVG_CORE_ASSERT(false, "Render API None is not supported!"); return nullptr;
			case RendererAPI::OpenGL: 
				return new OpenGLVertexArray();
		}

		DVG_CORE_ASSERT(false, "Unknown Renderer API!");
		return nullptr;
	}
}
