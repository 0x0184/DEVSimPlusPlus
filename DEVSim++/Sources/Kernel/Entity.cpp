#include "../../Includes/Kernel/Entity.hpp"

Entity::Entity()
	: Entity::Entity("") { }

Entity::Entity(std::string entity_name) {
	SetClassName("Entity");
	SetName(entity_name);
}

std::string Entity::GetClassName(void) {
	return ClassName;
}

void Entity::SetClassName(std::string classname) {
	ClassName = classname;
}

std::string Entity::GetName(void) {
	return Name;
}

void Entity::SetName(std::string entity_name) {
	Name = entity_name;
}