#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"

#include "SoonMoom/LayerStack.h"
#include "SoonMoom/Events/Event.h"
#include "SoonMoom/Events/ApplicationEvent.h"
#include "SoonMoom/ImGui/ImGuiLayer.h"

namespace SoonMoom
{

	class  Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImguiLayer = nullptr;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;

	};

	// To be define in CLINET
	Application* CreateApplication();

}


