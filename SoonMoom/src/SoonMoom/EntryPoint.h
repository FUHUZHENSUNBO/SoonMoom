#pragma once

#ifdef SM_PLATFORM_WINDOWS
extern SoonMoom::Application*  SoonMoom::CreateApplication();


int main(int argc,char** argv)
{
	SoonMoom::Log::Init();
	SM_CORE_TRACE("Initialized Log!");
	size_t a = 5;
	SM_INFO("Hello! Var={0}",a);
	auto app = SoonMoom::CreateApplication();
	app->Run();
	delete(app);
	return 0;
}
#endif