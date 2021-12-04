#pragma once
#include "smpch.h"
#include "Core.h"
#include "Log.h"
#include "Window.h"

#include "SoonMoom/LayerStack.h"
#include "SoonMoom/Events/Event.h"
#include "SoonMoom/Events/ApplicationEvent.h"
#include "SoonMoom/ImGui/ImGuiLayer.h"

#include "SoonMoom/Renderer/Shader.h"
#include "SoonMoom/Renderer/Buffer.h"

class VertexBuffer;
class  IndexBuffer;

namespace SoonMoom
{

	class  Application
	{

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImguiLayer = nullptr;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
		unsigned int m_vertextArray;

		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_vertexBuffer;
		std::unique_ptr<IndexBuffer> m_indexBuffer;


	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }



	};

	// To be define in CLINET
	Application* CreateApplication();

}


