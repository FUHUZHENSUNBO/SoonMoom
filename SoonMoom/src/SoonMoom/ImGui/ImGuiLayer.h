#pragma once
#include "SoonMoom/Core.h"
#include "SoonMoom/Events/MouseEvent.h"
#include "SoonMoom/Events/KeyEvent.h"
#include "SoonMoom/Events/ApplicationEvent.h"
namespace SoonMoom
{
	class  SOONMOOM_API ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();
		~ ImGuiLayer();
		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressdEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnWindowResizedEvent(WindowResizeEvent& event);
		bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		 
	private:
		float m_Time = 0.0f;
	};

}