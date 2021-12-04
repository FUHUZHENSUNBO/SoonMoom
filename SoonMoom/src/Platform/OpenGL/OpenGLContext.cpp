#include "smpch.h"
#include "OpenGLContext.h"


#include "GLFW/glfw3.h"
#include "glad/glad.h"


namespace SoonMoom
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_windowHandle(windowHandle)
	{
		SM_CORE_ASSERT(windowHandle, "Handle is null");
	}


	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SM_CORE_ASSERT(status, "Failed to initialize Glad !");
	}

	void OpenGLContext::SwapBuffers()
	{

		glfwSwapBuffers(m_windowHandle);
	}

}