#pragma once
#include "smpch.h"


namespace SoonMoom
{
	class GraphicsContext
	{
	public:
		virtual void Init()=0;
		virtual void SwapBuffers()=0;

	};

}