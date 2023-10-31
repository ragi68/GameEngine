#pragma once

#ifdef PROTO_PLATFORM_WINDOWS
#ifdef PROTO_DYNAMIC_LINK
	#ifdef PROTO_BUILD_DLL
		#define PROTO_API __declspec(dllexport)
	#else
		#define PROTO_API __declspec(dllimport)
	#endif
#else
	#define PROTO_API
#endif
#else
	#error Error
#endif

#ifdef PROTO_WINDOW_ENABLED
#define PROTO_LOG(x, ...){ if(!x){ PROTO_ERROR_MODULE("Setup failure:{0}", __VA_ARGS__); __debugbreak();}} //sets log to give error and stops code for debugging. 
#define PROTO_CORE_LOG(x, ...){if (!x){PROTO_CRITICAL_MODULE("Setup failure: {0}", __VA_ARGS__); __debugbreak();}}

#else
#define PROTO_LOG(x, ...)
#define PROTO_CORE_LOG(x, ...)
#endif

#define BIT(a) (1 << a)


