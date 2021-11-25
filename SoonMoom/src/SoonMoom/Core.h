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

#ifdef SM_DEBUG
#define SM_ENABLE_ASSERTS
#endif // SM_DEBUG



#ifdef SM_ENABLE_ASSERTS
    #define  SM_ASSERT(x,...){if(!(x)){SM_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
    #define  SM_CORE_ASSERT(x,...){if(!(x)){SM_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
    #define  SM_ASSERT(x,...)
    #define  SM_CORE_ASSERT(x,...)
#endif // SM_ENABLE_ASSERTS


#define  BIT(x) (1<<x)




