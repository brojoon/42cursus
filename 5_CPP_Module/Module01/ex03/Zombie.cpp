#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "defaultName";
	this->type = "defaultType";
}

Zombie::Zombie(std::string name, std::string type)
{
	this->name = name;
	this->type = type;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::setType(std::string type)
{
	this->type = type;
}

void Zombie::announce()
{
	std::cout << "<" << name << " (" << this->type << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}