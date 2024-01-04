#include "dvgpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "platform/OpenGL/OpenGLBuffer.h"

namespace dvg {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: DVG_CORE_ASSERT(false, "Render API None is not supported!"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		DVG_CORE_ASSERT(false, "Unknown Renderer API!")
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size) {
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: DVG_CORE_ASSERT(false, "Render API None is not supported!"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}

		DVG_CORE_ASSERT(false, "Unknown Renderer API!")
		return nullptr;
	}
}
