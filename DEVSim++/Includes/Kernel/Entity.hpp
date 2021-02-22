#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <iostream>

class Entity {
protected:
	std::string ClassName;
	std::string Name;
public:
	Entity();
	Entity(std::string);

	std::string GetClassName(void);
	void SetClassName(std::string);
	
	std::string GetName(void);
	void SetName(std::string);
};

#endif	// __ENTITY_HPP__