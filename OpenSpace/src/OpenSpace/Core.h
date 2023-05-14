#pragma once

#ifdef OP_PLATFORM_WINDOWS
	#ifdef OP_BUILD_DLL
		#define OPENSPACE_API __declspec(dllexport)
	#else
		#define OPENSPACE_API __declspec(dllimport)
	#endif
#else
	#error Openspace currently only supports windows
#endif