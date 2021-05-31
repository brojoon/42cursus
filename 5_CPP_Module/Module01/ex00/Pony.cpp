#include "Pony.hpp"

Pony::Pony(std::string name)
{
	this->name = name;
}

Pony::~Pony(void)
{
	std::cout << "Pony" << this->name << "destroyed!!" << std::endl;
}

void Pony::printName()
{
	std::cout << "Pony name: " << this->name << std::endl;
}