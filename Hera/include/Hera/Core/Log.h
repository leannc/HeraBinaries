#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "Base.h"

namespace Hera {
class HERA_API Log {
 public:
    enum class Type {
        Core = 0,
        Client
    };
    enum class Level {
        Trace = 0,
        Info,
        Warn,
        Error,
        Fatal
    };
    struct TagDetails {
        bool Enabled = true;
        Level LevelFilter = Level::Trace;
    };
    static void Init();
    static void Shutdown();
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetEditorConsoleLogger() { return s_EditorConsoleLogger; }
    static bool HasTag(const std::string& tag) { return s_EnabledTags.find(tag) != s_EnabledTags.end(); }
    static std::map<std::string, TagDetails>& EnabledTags() { return s_EnabledTags; }
    template<typename... Args>
    static void PrintMessage(Log::Type type, Log::Level level, std::string_view tag, Args&&... args);
    template<typename... Args>
    static void PrintAssertMessage(Log::Type type, std::string_view prefix, Args&&... args);

 public:
    // Enum utils
    static const char* LevelToString(Level level) {
        switch (level) {
            case Level::Trace: return "Trace";
            case Level::Info:  return "Info";
            case Level::Warn:  return "Warn";
            case Level::Error: return "Error";
            case Level::Fatal: return "Fatal";
        }
        return "";
    }
    static Level LevelFromString(std::string_view string) {
        if (string == "Trace") return Level::Trace;
        if (string == "Info")  return Level::Info;
        if (string == "Warn")  return Level::Warn;
        if (string == "Error") return Level::Error;
        if (string == "Fatal") return Level::Fatal;
        return Level::Trace;
    }

 private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
    static std::shared_ptr<spdlog::logger> s_EditorConsoleLogger;
    inline static std::map<std::string, TagDetails> s_EnabledTags;
};
}  // namespace Hera

namespace Hera {
template<typename... Args>
void Log::PrintMessage(Log::Type type, Log::Level level, std::string_view tag, Args&&... args) {
    auto detail = s_EnabledTags[std::string(tag)];
    if (detail.Enabled && detail.LevelFilter <= level) {
        auto logger = (type == Type::Core) ? GetCoreLogger() : GetClientLogger();
        const char* formatString = tag.empty() ? "{0}{1}" : "[{0}] {1}";
        switch (level) {
            case Level::Trace:
                logger->trace(fmt::runtime(formatString), tag, std::forward<Args>(args)...);
                break;
            case Level::Info:
                logger->info(fmt::runtime(formatString), tag, std::forward<Args>(args)...);
                break;
            case Level::Warn:
                logger->warn(fmt::runtime(formatString), tag, std::forward<Args>(args)...);
                break;
            case Level::Error:
                logger->error(fmt::runtime(formatString), tag, std::forward<Args>(args)...);
                break;
            case Level::Fatal:
                logger->critical(fmt::runtime(formatString), tag, std::forward<Args>(args)...);
                break;
        }
    }
}
template<typename... Args>
void Log::PrintAssertMessage(Log::Type type, std::string_view prefix, Args&&... args) {
    auto logger = (type == Type::Core) ? GetCoreLogger() : GetClientLogger();
    logger->error(fmt::runtime("{0}: {1}"), prefix, std::forward<Args>(args)...);
#if HERA_ASSERT_MESSAGE_BOX
    std::string message = fmt::format(std::forward<Args>(args)...);
    MessageBoxA(nullptr, message.c_str(), "Hera Assert", MB_OK | MB_ICONERROR);
#endif
}

template<>
inline void Log::PrintAssertMessage(Log::Type type, std::string_view prefix) {
    auto logger = (type == Type::Core) ? GetCoreLogger() : GetClientLogger();
    logger->error("{0}", prefix);
#if HERA_ASSERT_MESSAGE_BOX
        MessageBoxA(nullptr, "No message :(", "Hera Assert", MB_OK | MB_ICONERROR);
#endif
}
}  // namespace Hera

// SIDE-NOTE ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tagged logs (prefer these!)                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Core logging
#define HERA_CORE_TRACE_TAG(tag, ...) ::Hera::Log::PrintMessage(::Hera::Log::Type::Core, ::Hera::Log::Level::Trace, tag, __VA_ARGS__)
#define HERA_CORE_INFO_TAG(tag, ...)  ::Hera::Log::PrintMessage(::Hera::Log::Type::Core, ::Hera::Log::Level::Info, tag, __VA_ARGS__)
#define HERA_CORE_WARN_TAG(tag, ...)  ::Hera::Log::PrintMessage(::Hera::Log::Type::Core, ::Hera::Log::Level::Warn, tag, __VA_ARGS__)
#define HERA_CORE_ERROR_TAG(tag, ...) ::Hera::Log::PrintMessage(::Hera::Log::Type::Core, ::Hera::Log::Level::Error, tag, __VA_ARGS__)
#define HERA_CORE_FATAL_TAG(tag, ...) ::Hera::Log::PrintMessage(::Hera::Log::Type::Core, ::Hera::Log::Level::Fatal, tag, __VA_ARGS__)

// Client logging
#define HERA_TRACE_TAG(tag, ...) ::Hera::Log::PrintMessage(::Hera::Log::Type::Client, ::Hera::Log::Level::Trace, tag, __VA_ARGS__)
#define HERA_INFO_TAG(tag, ...)  ::Hera::Log::PrintMessage(::Hera::Log::Type::Client, ::Hera::Log::Level::Info, tag, __VA_ARGS__)
#define HERA_WARN_TAG(tag, ...)  ::Hera::Log::PrintMessage(::Hera::Log::Type::Client, ::Hera::Log::Level::Warn, tag, __VA_ARGS__)
#define HERA_ERROR_TAG(tag, ...) ::Hera::Log::PrintMessage(::Hera::Log::Type::Client, ::Hera::Log::Level::Error, tag, __VA_ARGS__)
#define HERA_FATAL_TAG(tag, ...) ::Hera::Log::PrintMessage(::Hera::Log::Type::Client, ::Hera::Log::Level::Fatal, tag, __VA_ARGS__)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Core log macros
#define HERA_CORE_TRACE(...)    ::Hera::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HERA_CORE_INFO(...)     ::Hera::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HERA_CORE_WARN(...)     ::Hera::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HERA_CORE_ERROR(...)    ::Hera::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HERA_CORE_FATAL(...)    ::Hera::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define HERA_TRACE(...)    ::Hera::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HERA_INFO(...)     ::Hera::Log::GetClientLogger()->info(__VA_ARGS__)
#define HERA_WARN(...)     ::Hera::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HERA_ERROR(...)    ::Hera::Log::GetClientLogger()->error(__VA_ARGS__)
#define HERA_FATAL(...)    ::Hera::Log::GetClientLogger()->critical(__VA_ARGS__)
