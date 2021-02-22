#include "../../Includes/Kernel/Coupled.hpp"

Coupled::Coupled(std::string entity_name) : Model(entity_name) {
	SetClassName("Coupled");
}

void Coupled::AddChild(Model* model) {
	Children.AddOne(model);
}

void Coupled::AddChild(Model* model, double wait_time) {
	Children.AddOne(model, wait_time);
}

int Coupled::IsDevsChild(Model* model) {
	return Children.IsIn(model);
}

int Coupled::NumOfChild(void) {
	return Children.GetLength();
}