#include "../../Includes/Kernel/Message.hpp"

void DevsMessage::MakeContent(std::string P, std::string V){
	Port = P;
	Value = V;
}

std::string DevsMessage::ContentPort() {
	return Port;
}

std::string DevsMessage::ContentValue() {
	return Value;
}