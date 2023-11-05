#include <APL/Logger.h>

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdarg>

namespace Logs
{
	FileSink::FileSink(const std::string& _fileName, std::size_t _bufferSize)
		: m_buffer(_bufferSize), m_output(_fileName), m_offset(0u)
	{
		if (!m_output.is_open())
		{
			throw std::runtime_error("File was not created");
		}
	}

	void FileSink::write(const std::string& _data)
	{
		const std::size_t dataSize = _data.size();
		std::lock_guard<std::mutex> lock(m_mutex);
		if (dataSize + m_offset >= m_buffer.size())
		{
			flush();
		}

		std::copy(begin(_data), end(_data), begin(m_buffer) + m_offset);
		m_offset += dataSize;
	}

	FileSink::~FileSink()
	{
		flush();
	}

	void FileSink::flush()
	{
		if (m_offset != 0u)
		{
			m_output.write(m_buffer.data(), m_offset);
			m_offset = 0u;
		}
	}

	Logger::Logger(const std::string& _fileName, bool _logToConsole)
		: m_sink(_fileName), m_logToConsole(_logToConsole)
	{

	}

	void Logger::log(Level _level, const std::string& _message)
	{
		const std::string formattedMessage = "[" + getTimeStamp() + "] [" + LevelStr[_level] + "]: " + _message + "\n";

		m_sink.write(formattedMessage);

		if (m_logToConsole)
		{
			std::cout << formattedMessage;
		}
	}

	void Logger::log(Level _level, const char* format, ...)
	{
		va_list length_args;

		va_start(length_args, format);
		va_list result_args;

		va_copy(result_args, length_args);
		const auto length = vsnprintf(nullptr, 0U, format, length_args);
		std::string result(length, '\0');

		vsprintf(data(result), format, result_args);
		va_end(result_args);
		va_end(length_args);

		const std::string formattedMessage = "[" + getTimeStamp() + "] [" + LevelStr[_level] + "]: " + result + "\n";

		m_sink.write(formattedMessage);

		if (m_logToConsole)
		{
			std::cout << formattedMessage;
		}
	}

	std::string Logger::getTimeStamp()
	{
		const std::time_t now = std::time(nullptr);
		std::tm tm = {};
		std::stringstream ss;
		ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
		return ss.str();
	}
}