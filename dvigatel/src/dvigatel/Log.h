#pragma once

#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace dvg {

	class DVG_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define DVG_CORE_ERROR(...) ::dvg::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DVG_CORE_WARN(...)	::dvg::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DVG_CORE_INFO(...)	::dvg::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DVG_CORE_TRACE(...) ::dvg::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DVG_CORE_FATAL(...) ::dvg::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DVG_ERROR(...)	::dvg::Log::GetClientLogger()->error(__VA_ARGS__)
#define DVG_WARN(...)	::dvg::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DVG_INFO(...)	::dvg::Log::GetClientLogger()->info(__VA_ARGS__)
#define DVG_TRACE(...)	::dvg::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DVG_FATAL(...)	::dvg::Log::GetClientLogger()->fatal(__VA_ARGS__)
