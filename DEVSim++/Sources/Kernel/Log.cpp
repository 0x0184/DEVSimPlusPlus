#include "../../Includes/Kernel/Log.hpp"

#include <string>
#include <iostream>

void Log(std::string message) {
	std::cout << message;
}

void Logln(std::string message) {
	std::cout << message << std::endl;
}

void Logerr(std::exception error) {
	std::cerr << error.what() << std::endl;
}