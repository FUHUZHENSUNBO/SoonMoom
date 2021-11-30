#include <SoonMoom.h>
#include "imgui/imgui.h"



class  ExampleLayer:public SoonMoom::Layer
{
public:
	ExampleLayer() :Layer("Example") 
	{
		
	}
	
	void OnUpdate()override
	{
		//SM_INFO("ExampleLayer::Update");

		if (SoonMoom::Input::IsKeyPressed(SM_KEY_TAB))
		{
			SM_TRACE("Tab key is pressed!(poll)");
		}
	}  

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(SoonMoom::Event& event)override
	{
		if (event.GetEventType() == SoonMoom::EventType::KeyPressed)
		{
			SoonMoom::KeyPressedEvent& e = static_cast<SoonMoom::KeyPressedEvent&>(event);
			if (e.GetKeyCode()==SM_KEY_TAB)
			{
				SM_TRACE("Tab key is pressed!(event)");
			}
			SM_TRACE("{0}",(char)e.GetKeyCode());
		}

	}
};




class Sandbox :public SoonMoom::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		
	}
	~Sandbox() 
	{

	}

};

SoonMoom::Application* SoonMoom::CreateApplication()
{
	return new Sandbox();
}


