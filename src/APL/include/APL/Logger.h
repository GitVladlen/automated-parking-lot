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
		// Constructor for the FileSink with an optional buffer size
		FileSink(const std::string& _fileName, std::size_t _bufferSize = 4096u);

		// Write a log message to the file sink
		void write(const std::string& _data);

		// Destructor that ensures the buffer is flushed
		~FileSink();

	private:
		// Flush the buffer to the output file
		void flush();

	private:
		std::vector<char> m_buffer;   // Buffer for log messages
		std::ofstream m_output;       // Output file stream
		std::size_t m_offset;         // Current offset in the buffer
		std::mutex m_mutex;           // Mutex for thread safety
	};

	class Logger
	{
	public:
		// Log levels
		enum Level
		{
			TRACE_LEVEL,
			DEBUG_LEVEL,
			INFO_LEVEL,
			WARN_LEVEL,
			ERROR_LEVEL,
			FATAL_LEVEL
		};

		// Array of log level strings
		static inline std::array<std::string, Level::FATAL_LEVEL + 1u> LevelStr = {
			"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
		};

	public:
		// Constructor for the Logger with an output file and an option to log to the console
		Logger(const std::string& _fileName, bool _logToConsole = true);

		// Log a message with a specified log level
		void log(Level _level, const std::string& _message);

		// Log a formatted message with a specified log level and variadic arguments
		void log(Level _level, const char* format, ...);

	private:
		// Generate a timestamp for log entries
		std::string getTimeStamp();

	private:
		FileSink m_sink;       // File sink for log messages
		bool m_logToConsole;   // Flag to indicate whether to log to the console
	};
}

// Global logger instance accessible via macros
inline Logs::Logger& getGlobalLogger()
{
	static Logs::Logger logger("data.log");
	return logger;
}

// Macros for logging with various log levels and format specifiers
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
