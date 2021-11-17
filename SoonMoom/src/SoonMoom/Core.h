#pragma once

#ifdef SM_PLATFORM_WINDOWS
	#ifdef  SM_BUIILD_DLL
		#define SOONMOOM_API __declspec(dllexport) 
	#else
		#define SOONMOOM_API __declspec(dllimport) 
	#endif
#else
	#error SoonMoom only support Windows!
#endif