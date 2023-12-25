#pragma once

#ifdef DVG_PLATFORM_WINDOWS
	#ifdef DVG_BUILD_DLL
		#define DVG_API __declspec(dllexport)
	#else
		#define DVG_API __declspec(dllimport)
	#endif
#else
	#error dvigatel only support Windows!
#endif
