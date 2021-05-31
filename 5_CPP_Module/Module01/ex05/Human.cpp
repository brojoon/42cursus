#include "Human.hpp"

const Brain &Human::getBrain() const
{
	return breain;
}

std::string Human::identify() const
{
	return getBrain().identify();
}