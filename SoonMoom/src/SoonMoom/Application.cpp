#include "smpch.h"
#include "Application.h"
#include "SoonMoom/Events/ApplicationEvent.h"


namespace SoonMoom
{
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

}


