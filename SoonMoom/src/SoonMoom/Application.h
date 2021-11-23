#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"

namespace SoonMoom
{

	class SOONMOOM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be define in CLINET
	Application* CreateApplication();

}


