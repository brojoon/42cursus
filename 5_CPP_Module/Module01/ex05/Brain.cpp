#include "Brain.hpp"

std::string Brain::identify() const
{
	std::stringstream address;
	address << this;
	return address.str();
}