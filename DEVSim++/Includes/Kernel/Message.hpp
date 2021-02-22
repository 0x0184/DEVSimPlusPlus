#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include "DEVSDEF.h"
#include <string>

class DevsMessage {
private:
	  std::string   Port;
	  std::string	Value;
public:
    void      MakeContent(std::string, std::string);
	//double    ContentTime();
	std::string ContentPort();
	std::string ContentValue();
};

#endif	// __MESSAGE_HPP__