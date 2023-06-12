#include "PrecompiledHeaders.h"
#include "logging.h"

namespace Proto {
	std::shared_ptr<spdlog::logger> logging::Logger;
	std::shared_ptr<spdlog::logger> logging::ClientLogger;
	
	void logging::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		Logger = spdlog::stdout_color_mt("Main Logger");

		Logger->set_level(spdlog::level::trace);
		ClientLogger = spdlog::stdout_color_mt("Client Logger");
		ClientLogger->set_level(spdlog::level::trace);


	}
}