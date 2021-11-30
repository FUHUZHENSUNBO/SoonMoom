#include "smpch.h"
#include "WindowsWindow.h"
#include "SoonMoom/Log.h"
#include "SoonMoom/Events/ApplicationEvent.h"
#include "SoonMoom/Events/MouseEvent.h"
#include "SoonMoom/Events/KeyEvent.h"
#include <glad/glad.h>




namespace SoonMoom {
	
	static bool s_GLFWInitiallized = false;
	static void GLFWErrorCallback(int error_code, const char* description)
	{
		SM_CORE_ERROR("GLFW Error! ({0}):{1}", error_code, description);
	}
	
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

	

		SM_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		//m_Context = new OpenGLContext();


		if (!s_GLFWInitiallized)
		{
			int success = glfwInit();
			SM_CORE_ASSERT(success,"Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitiallized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
	
		//m_Context->Init();

		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SM_CORE_ASSERT(status, "Failed to initialize Glad !");
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);


		//Set GLFW callbacks

		/// <summary>
		/// 屏幕尺寸回调
		/// </summary>
		/// <param name="props"></param>
		glfwSetWindowSizeCallback(m_Window, 
			[](GLFWwindow* window,int width,int height) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			}
		);

		/// <summary>
		/// 窗口关闭回调
		/// </summary>
		/// <param name="props"></param>
		glfwSetWindowCloseCallback(m_Window, 
			[](GLFWwindow* window) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		/// <summary>
		/// 键盘按键回调
		/// </summary>
		/// <param name="props"></param>
		glfwSetKeyCallback(m_Window, 
			[](GLFWwindow* window,int key,int scancode,int action,int mods) 
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.EventCallback(event);
						break;
					}

					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(key);
						data.EventCallback(event);
						break;
					}

					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.EventCallback(event);
						break;
					}

					default:
					{
						break;
					}
				}
			}
		);


		glfwSetCharCallback(m_Window,
			[](GLFWwindow* window, unsigned int codepoint)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyTypedEvent event(codepoint);
				data.EventCallback(event);
			}
		);


		/// <summary>
		/// 鼠标案件回调
		/// </summary>
		/// <param name="props"></param>
		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window,int button,int action,int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				default:
					break;
				}

			}
		);

		/// <summary>
		/// 鼠标滑轮滚动回调
		/// </summary>
		/// <param name="props"></param>
		glfwSetScrollCallback(m_Window,
			[](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xoffset, (float)yoffset);
				data.EventCallback(event);
			}
		);

		/// <summary>
		/// 鼠标移动回调
		/// </summary>
		/// <param name="props"></param>
		glfwSetCursorPosCallback(m_Window,
			[](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xpos, (float)ypos);
				data.EventCallback(event);
			}
		);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);

	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		//m_Context->SwapBuffers();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}
