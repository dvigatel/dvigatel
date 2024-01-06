#include "dvgpch.h"
#include "RenderCommand.h"

#include "platform/OpenGL/OpenGLRendererAPI.h"

namespace dvg {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}