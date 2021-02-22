#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <string>

void Log(std::string);
void Logln(std::string message = "");
void Logerr(std::exception);

#endif  // __LOG_HPP__