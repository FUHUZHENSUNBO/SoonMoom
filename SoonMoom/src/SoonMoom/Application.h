#pragma once
#include "Core.h"


namespace SoonMoom
{

	class SOONMOOM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:

	};

	// To be define in CLINET
	Application* CreateApplication();

}


