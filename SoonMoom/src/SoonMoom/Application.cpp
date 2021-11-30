 #include "smpch.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Application.h"
#include "SoonMoom/Input.h"



namespace SoonMoom
{


	 Application* Application::s_Instance = nullptr;


	Application::Application()
	{
		SM_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(SM_BIND_EVENT_FN(Application::OnEvent));
		m_ImguiLayer = new ImGuiLayer();
		PushOverlay(m_ImguiLayer);
	}

	Application::~Application()
	{
		
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(SM_BIND_EVENT_FN(Application::OnWindowClosed));
		SM_CORE_TRACE("{0}",e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if(e.m_Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		WindowResizeEvent e(0, 0);
		
		while (m_Running)
		{
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer :m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImguiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImguiLayer->End();

			m_Window->OnUpdate();
		}
	}

}


