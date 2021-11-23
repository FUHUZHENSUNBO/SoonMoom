#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "SoonMoom/Events/ApplicationEvent.h"
namespace SoonMoom
{

	class SOONMOOM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be define in CLINET
	Application* CreateApplication();

}


