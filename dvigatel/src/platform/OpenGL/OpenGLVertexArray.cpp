#include "dvgpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace dvg {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) {
		switch (type)
		{
		case dvg::ShaderDataType::Float: return GL_FLOAT;
		case dvg::ShaderDataType::Float2:return GL_FLOAT;
		case dvg::ShaderDataType::Float3:return GL_FLOAT;
		case dvg::ShaderDataType::Float4:return GL_FLOAT;
		case dvg::ShaderDataType::Mat3: return GL_FLOAT;
		case dvg::ShaderDataType::Mat4: return GL_FLOAT;
		case dvg::ShaderDataType::Int: return GL_INT;
		case dvg::ShaderDataType::Int2: return GL_INT;
		case dvg::ShaderDataType::Int3: return GL_INT;
		case dvg::ShaderDataType::Int4: return GL_INT;
		case dvg::ShaderDataType::Bool: return GL_BOOL;
		}
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray() 
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vbuffer)
	{
		DVG_CORE_ASSERT(VertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");
		glBindVertexArray(m_RendererID);
		vbuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vbuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vbuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& ibuffer)
	{
		glBindVertexArray(m_RendererID);
		ibuffer->Bind();

		m_IndexBuffer = ibuffer;
	}

}
