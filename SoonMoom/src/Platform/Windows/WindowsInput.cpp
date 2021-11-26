#include "smpch.h"
#include "WindowsInput.h"
#include "SoonMoom/Application.h"
#include <GLFW/glfw3.h>
#include "SoonMoom/Log.h"
namespace SoonMoom
{

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keyCode);
		return  state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return  state == GLFW_PRESS  || state == GLFW_RELEASE;
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto v = GetMousePositionImpl();
		return std::get<0>(v);
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto v = GetMousePositionImpl();
		return std::get<1>(v);
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos = 0.0;
		double yPos = 0.0;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { (float)xPos,(float)yPos };
	}

}