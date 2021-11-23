#include "smpch.h"
#include "Application.h"
#include "SoonMoom/Events/ApplicationEvent.h"


namespace SoonMoom
{
	
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SM_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			SM_TRACE(e);
		}

		while (true);
	}

}


