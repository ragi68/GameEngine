#pragma once

#ifdef PROTO_PLATFORM_WINDOWS
	#ifdef PROTO_BUILD_DLL
		#define PROTO_API __declspec(dllexport)
	#else
		#define PROTO_API __declspec(dllimport)
	#endif
#else
	#error Error
#endif

#define BIT(a) (1 << a)