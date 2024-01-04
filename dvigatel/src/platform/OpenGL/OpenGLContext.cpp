#include "dvgpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace dvg {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		DVG_CORE_ASSERT(windowHandle, "Window handle is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DVG_CORE_ASSERT(status, "Failed to init Glad");

		DVG_CORE_INFO("Vendor: {0}", (const char*) glGetString(GL_VENDOR));
		DVG_CORE_INFO("Renderer: {0}", (const char*) glGetString(GL_RENDERER));
		DVG_CORE_INFO("Version: {0}", (const char*) glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}