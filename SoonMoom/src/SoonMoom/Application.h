#pragma once
#include "Core.h"
#include "SoonMoom/Log.h"

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


