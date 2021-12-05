#include "smpch.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Application.h"
#include "SoonMoom/Input.h"
#include "glm/glm.hpp"

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


		float vertices[3 * 7] = {
		   -0.5f , -0.5f, 0.0f,1.0,0.0,1.0,1.0,
			0.5f , -0.5f, 0.0f,1.0,0.0,1.0,1.0,
			0.0f ,  0.5f, 0.0f,1.0,0.0,1.0,1.0
		};
		
		uint32_t indices[3] = { 0,1,2 };



		//Vertex Array 
		m_VertexArray.reset(VertexArray::Creat());
		m_VertexArray->Bind();


		//Vertex Buffer
		m_VertexBuffer.reset( VertexBuffer::Create(vertices, sizeof(vertices)));

		//Index Buffer
		m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices)/sizeof(uint32_t)));

		//set layout for vertexBuffer
		{
			BufferLayout layout =
			{
				{"a_Position",ShaderDataType::Float3},
				{"a_Color",ShaderDataType::Float4}
			};
			m_VertexBuffer->SetLayout(layout);

		}
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);
		


		////glEnableVertexAttribArray(0);
		////glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), nullptr);

		////glEnableVertexAttribArray(1);
		////glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (const void*)12);
			
		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			out vec4 v_color;
			out vec3 v_Position;
			void main()
			{
				v_Position=a_Position;
				v_color=a_Color;
				gl_Position = vec4(a_Position,1.0);
			})";


	std::string fragmentSrc = R"(
            #version 330 core

			layout(location = 0) out vec4 color;

			in vec4 v_color;
			in vec3 v_Position;

            void main()
			{
				color = vec4(v_Position*0.5+0.5,1.0);
				color = v_color;
			}
		)";

		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));// = std::make_unique<Shader>();

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
		//设置屏幕窗口大小
		//glfwSetWindowSize(static_cast<GLFWwindow*>(m_Window->GetNativeWindow()), 780, 500);
		while (m_Running)
		{
			glClearColor(0.0f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			m_VertexArray->Bind();

			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);


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


