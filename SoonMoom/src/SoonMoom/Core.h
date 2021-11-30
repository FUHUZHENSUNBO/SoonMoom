#pragma once

#ifdef SM_PLATFORM_WINDOWS

    #if SM_DYNAMIC_LINK
        #ifdef  SM_BUILD_DLL
    		#define  SOONMOOM_API __declspec(dllexport) 
    	#else
    		#define  SOONMOOM_API __declspec(dllimport) 
    	#endif
    #else
        #ifndef SOONMOOM_DEBUG
            #define SOONMOOM_DEBUG
        #endif
    #endif
#else

    #error SoonMoom only supports Windows!
#endif // SM_PLATFORM_WINDOWS
                    
#ifdef SM_ENABLE_ASSERTS

    #define  SM_ASSERT(x,...){if(!(x)){SM_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
    #define  SM_CORE_ASSERT(x,...){if(!(x)){SM_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else

    #define  SM_ASSERT(x,...)
    #define  SM_CORE_ASSERT(x,...)
#endif // SM_ENABLE_ASSERTS

#define  BIT(x) (1<<x)


#ifndef SM_BIND_EVENT_FN(fn)

    #define SM_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#endif

#ifndef SM_WINDOWS_GLFW_INPUT_CODE

    #define SM_WINDOWS_GLFW_INPUT_CODE
#endif
