#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "SoonMoom/LayerStack.h"
#include "SoonMoom/Events/Event.h"
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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	// To be define in CLINET
	Application* CreateApplication();

}


