#pragma once
#include "SoonMoom/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace SoonMoom
{
	class SOONMOOM_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

// Core log macros

#define SM_CORE_TRACE(...) ::SoonMoom::Log::GetCoreLogger()->trace(__VA_ARGS__)	
#define SM_CORE_INFO(...)   ::SoonMoom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SM_CORE_WARN(...)  ::SoonMoom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SM_CORE_ERROR(...) ::SoonMoom::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SM_CORE_FATAL(...) ::SoonMoom::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros

#define SM_TRACE(...) ::SoonMoom::Log::GetClientLogger()->trace(__VA_ARGS__)	
#define SM_INFO(...)   ::SoonMoom::Log::GetClientLogger()->info(__VA_ARGS__)
#define SM_WARN(...)  ::SoonMoom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SM_ERROR(...) ::SoonMoom::Log::GetClientLogger()->error(__VA_ARGS__)
#define SM_FATAL(...) ::SoonMoom::Log::GetClientLogger()->fatal(__VA_ARGS__)