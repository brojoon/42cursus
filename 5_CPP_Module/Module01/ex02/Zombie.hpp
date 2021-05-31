#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;
		std::string type;
	
	public:
		Zombie(std::string name, std::string type);
		~Zombie(void);
		void announce(void);
};

#endif