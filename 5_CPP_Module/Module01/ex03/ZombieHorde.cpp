#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	if (n <= 0)
	{
		std::cout << "Wrong Horder number!!!" << std::endl;
		return ;
	}
	this->zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		this->zombies[i].
	}
}

void ZombieHorde::announce()
{
	for (int i = 0; i < zombieNum; i++)
	{
		zombies[i].announce();
	}
}

ZombieHorder::~ZombieHorde()
{
	delete[] zombies;
}