#pragma once

#include "EntryCore.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
namespace Proto {
	class PROTO_API logging
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return Logger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> Logger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};
}
//sets logging states of both the client and maker side
#define PROTO_ERROR_MODULE(...) ::Proto::logging::GetLogger()->error(__VA_ARGS__);
#define PROTO_WARNING_MODULE(...) ::Proto::logging::GetLogger()->warn(__VA_ARGS__);
#define PROTO_TRACE_MODULE(...) ::Proto::logging::GetLogger()->trace(__VA_ARGS__);
#define PROTO_INFO_MODULE(...) ::Proto::logging::GetLogger()->info(__VA_ARGS__);
#define PROTO_FATAL_MODULE(...) ::Proto::logging::GetLogger()->fatal(__VA_ARGS__);
#define PROTO_CRITICAL_MODULE(...) ::Proto::logging::GetLogger()->critical(__VA_ARGS__);

#define CLIENT_ERROR_MODULE(...) ::Proto::logging::GetLogger()->error(__VA_ARGS__);
#define CLIENT_WARNING_MODULE(...) ::Proto::logging::GetLogger()->warn(__VA_ARGS__);
#define CLIENT_TRACE_MODULE(...) ::Proto::logging::GetLogger()->trace(__VA_ARGS__);
#define CLIENT_INFO_MODULE(...) ::Proto::logging::GetLogger()->info(__VA_ARGS__);
#define CLIENT_FATAL_MODULE(...) ::Proto::logging::GetLogger()->fatal(__VA_ARGS__);
#define CLIENT_CRITICAL_MODULE(...) ::Proto::logging::GetLogger()->critical(__VA_ARGS__);