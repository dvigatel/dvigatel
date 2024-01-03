#pragma once

#ifdef DVG_PLATFORM_WINDOWS
#if DVG_DYNAMIC_LINK
	#ifdef DVG_BUILD_DLL
		#define DVG_API __declspec(dllexport)
	#else
		#define DVG_API __declspec(dllimport)
	#endif
#else
	#define DVG_API
#endif
#else
	#error dvigatel only support Windows!
#endif

#ifdef DVG_ENABLE_ASSERTS
	#define DVG_ASSERT(x, ...) { if(!x) { DVG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DVG_CORE_ASSERT(x, ...) { if(!(x)) { DVG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DVG_ASSERT(x, ...)
	#define DVG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)


#define DVG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
