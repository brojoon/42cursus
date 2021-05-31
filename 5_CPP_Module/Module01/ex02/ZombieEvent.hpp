#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string type;
	public:
		void setZombieType(std::string type);
		Zombie *newZombie(std::string name);
		Zobie *randomChump(void);
};

#endif