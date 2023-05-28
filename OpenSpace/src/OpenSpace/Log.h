#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace OpenSpace {

	class OPENSPACE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

// Core log macros
#define OP_CORE_TRACE(...) ::OpenSpace::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OP_CORE_INFO(...) ::OpenSpace::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OP_CORE_WARN(...) ::OpenSpace::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OP_CORE_ERROR(...) ::OpenSpace::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OP_CORE_FATAL(...) ::OpenSpace::Log::GetCoreLogger()->critical(__VA_ARGS__)


// Client log macros
#define OP_TRACE(...) ::OpenSpace::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OP_INFO(...) ::OpenSpace::Log::GetClientLogger()->info(__VA_ARGS__)
#define OP_WARN(...) ::OpenSpace::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OP_ERROR(...) ::OpenSpace::Log::GetClientLogger()->error(__VA_ARGS__)
#define OP_FATAL(...) ::OpenSpace::Log::GetClientLogger()->critical(__VA_ARGS__)