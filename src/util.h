#ifndef UTIL_H
#define UTIL_H

#include <string>

#define DEBUG_INFO __FUNCTION__, __FILE__, __LINE__

struct Error {
	const std::string message;
	const std::string filePath;
	const std::string function;
	const std::string source;
	const std::string line;
};

void assert(const bool& assertion, const std::string& message, const std::string& filePath, const std::string& function, const std::string& source, const uint32_t& line);
std::string byte_to_string(const uint8_t& byte);

#endif // UTIL_H
