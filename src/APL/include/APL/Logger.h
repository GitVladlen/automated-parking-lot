#pragma once

#include <array>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>

namespace Logs
{
	class FileSink
	{
	public:
		FileSink(const std::string& _fileName, std::size_t _bufferSize = 4096u);

		void write(const std::string& _data);

		~FileSink();

	private:
		void flush();

	private:
		std::vector<char> m_buffer;
		std::ofstream m_output;
		std::size_t m_offset;
		std::mutex m_mutex;
	};

	class Logger
	{
	public:
		enum Level
		{
			TRACE_LEVEL,
			DEBUG_LEVEL,
			INFO_LEVEL,
			WARN_LEVEL,
			ERROR_LEVEL,
			FATAL_LEVEL
		};

		static inline std::array<std::string, Level::FATAL_LEVEL + 1u> LevelStr = {
			"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
		};

	public:
		Logger(const std::string& _fileName, bool _logToConsole = true);

		void log(Level _level, const std::string& _message);
		void log(Level _level, const char* format, ...);

	private:
		std::string getTimeStamp();

	private:
		FileSink m_sink;
		bool m_logToConsole;
	};
}

inline Logs::Logger& getGlobalLogger()
{
	static Logs::Logger logger("data.log");
	return logger;
}

#define LOG_TRACE(message) getGlobalLogger().log(Logs::Logger::Level::TRACE_LEVEL, (message))
#define LOG_DEBUG(message) getGlobalLogger().log(Logs::Logger::Level::DEBUG_LEVEL, (message))
#define LOG_INFO(message) getGlobalLogger().log(Logs::Logger::Level::INFO_LEVEL, (message))
#define LOG_WARN(message) getGlobalLogger().log(Logs::Logger::Level::WARN_LEVEL, (message))
#define LOG_ERROR(message) getGlobalLogger().log(Logs::Logger::Level::ERROR_LEVEL, (message))
#define LOG_FATAL(message) getGlobalLogger().log(Logs::Logger::Level::FATAL_LEVEL, (message))

#define LOG_TRACE_FMT(format, ...) getGlobalLogger().log(Logs::Logger::TRACE_LEVEL, format, ##__VA_ARGS__)
#define LOG_DEBUG_FMT(format, ...) getGlobalLogger().log(Logs::Logger::DEBUG_LEVEL, format, ##__VA_ARGS__)
#define LOG_INFO_FMT(format, ...) getGlobalLogger().log(Logs::Logger::INFO_LEVEL, format, ##__VA_ARGS__)
#define LOG_WARN_FMT(format, ...) getGlobalLogger().log(Logs::Logger::WARN_LEVEL, format, ##__VA_ARGS__)
#define LOG_ERROR_FMT(format, ...) getGlobalLogger().log(Logs::Logger::ERROR_LEVEL, format, ##__VA_ARGS__)
#define LOG_FATAL_FMT(format, ...) getGlobalLogger().log(Logs::Logger::FATAL_LEVEL, format, ##__VA_ARGS__)