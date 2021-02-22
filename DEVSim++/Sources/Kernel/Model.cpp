#include "../../Includes/Kernel/Model.hpp"

Model::Model()
	: Model::Model("") { }

Model::Model(std::string entity_name)
	: Model::Model(entity_name, nullptr) { }

Model::Model(std::string entity_name, Model* parent_model) {
	SetClassName("Model");
	SetName(entity_name);
	Parent = parent_model;
}

int Model::AddCoupling(Model* from_model, Model* to_model, std::string from_port, std::string to_port) {
	return Ports.AddCoupling((Entity*) from_model, (Entity*) to_model, from_port, to_port);
}

Model* Model::GetParent(void) {
	return Parent;
}

void Model::SetParent(Model* parent) {
	Parent = parent;
}

double Model::GetLastEventTime(void) {
	return LastEventTime;
}

void Model::SetLastEventTime(double time) {
	LastEventTime = time;
}

double Model::GetNextEventTime(void) {
	return NextEventTime;
}

void Model::SetNextEventTime(double time) {
	NextEventTime = time;
}

DevsMessage Model::GetInMessage(void) {
	return InMessage;
}

void Model::SetInMessage(DevsMessage message) {
	InMessage = message;
}

DevsMessage Model::GetOutMessage(void) {
	return OutMessage;
}

void Model::SetOutMessage(DevsMessage message) {
	OutMessage = message;
}