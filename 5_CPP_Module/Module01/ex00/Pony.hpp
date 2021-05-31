#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class Pony {
	private:
		std::string name;
	
	public:
		Pony(std::string name);
		~Pony(void);
		void printName(void);
};

#endif