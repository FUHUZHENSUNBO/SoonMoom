#include <SoonMoom.h>

class ExampleLayer:public SoonMoom::Layer
{
public:
	ExampleLayer() :Layer("Example") {};
	
	void OnUpdate()override
	{
		SM_INFO("ExampleLayer::Update");
	}

	void OnEvent(SoonMoom::Event& event)override
	{
		SM_INFO("{0}", event);
	}
};




class Sandbox :public SoonMoom::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new SoonMoom::ImGuiLayer());
	}
	~Sandbox() 
	{

	}

};

SoonMoom::Application* SoonMoom::CreateApplication()
{
	return new Sandbox();
}