#pragma once

#define PLATFORM_WINDOWS
#define HERA_ENABLE_ASSERTS

// SIDE-NOTE:让Hera中的API能够被外部使用
#ifdef PLATFORM_WINDOWS
    #ifdef HERA_DYNAMIC_LINK
        #ifdef ENGINE_BUILD_DLL
            #define HERA_API __declspec(dllexport)
        #else
            #define HERA_API __declspec(dllimport)
        #endif
    #else
        #define HERA_API
    #endif
#elif PLATFORM_LINUX
        #define HERA_API  __attribute__((visibility("default")))
#endif

#ifdef HERA_ENABLE_ASSERTS
    #ifdef PLATFORM_WINDOWS
        #define HERA_ASSERT(x, ...)  if(!(x)) { HERA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }
        #define HERA_CORE_ASSERT(x, ...)  if(!(x)) { HERA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }
    #else
        #include <csignal>
        #define HERA_ASSERT(x, ...) { if(!(x)) { HERA_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); } }
        #define HERA_CORE_ASSERT(x, ...) { if(!(x)) { HERA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); raise(SIGTRAP); } }
    #endif
#else
#define HERA_CORE_ASSERT(condition, ...)
#define HERA_ASSERT(condition, ...)
#endif