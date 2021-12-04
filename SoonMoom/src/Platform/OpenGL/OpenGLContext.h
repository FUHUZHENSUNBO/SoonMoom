#pragma once
#include "SoonMoom/Renderer/GraphicsContext.h"


struct GLFWwindow;
namespace SoonMoom
{


	class OpenGLContext :public GraphicsContext
	{
	private:
		GLFWwindow* m_windowHandle=nullptr;


	public:
		OpenGLContext(GLFWwindow* windowHandle);
		~OpenGLContext();
		virtual void Init()override;
		virtual void SwapBuffers()override;
	};



}