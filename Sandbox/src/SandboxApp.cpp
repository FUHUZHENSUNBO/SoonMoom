#include <SoonMoom.h>

class Sandbox :public SoonMoom::Application
{
public:
	Sandbox() {}
	~Sandbox() {}

};

SoonMoom::Application* SoonMoom::CreateApplication()
{
	return new Sandbox();
}