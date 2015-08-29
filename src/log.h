#pragma once

#include <iostream>

namespace zubr {
namespace log {

enum class level {
	TRACE,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

std::string to_string(level lvl)
{
	std::string str = "UNKNOWN";
	switch (lvl) {
		case level::TRACE:
			str = "TRACE";
			break;
		case level::DEBUG:
			str = "DEBUG";
			break;
		case level::INFO:
			str = "INFO";
			break;
		case level::WARNING:
			str = "WARN";
			break;
		case level::ERROR:
			str = "ERROR";
			break;
		case level::CRITICAL:
			str = "CRITICAL";
			break;
	}
	return str;
}


class logger {
public:
	template<typename... params>
	void operator()(level lvl, params... p)
	{
		if (lvl >= log_level) {
			std::cout << "[" << to_string(lvl) << "]";
			do_log(p...);
			std::cout << std::endl;
		}	
	}

	void set_log_level(level lvl)
	{
		log_level = lvl;
	}
private:
	template<typename T>
	inline void do_log(T&& data)
	{
		std::cout << data;
	}	

	template<typename T, typename... params>
	inline void do_log(T&& data, params... p)
	{
		do_log(data);
		do_log(p...);	
	}	

	level log_level = level::DEBUG;
};

} // namespace log
} // namespace zubr
