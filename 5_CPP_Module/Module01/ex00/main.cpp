#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *heapPony = new Pony("new heap pony");
	heapPony->printName();
	std::cout << "delete heap pony" << std::endl;
	delete pony;
}

void ponyOnTheStack()
{
	Pony stackpony("new stack pony");
	stackPony.printName();
	std::cout << "delete stack pony" << std::endl;
}

int main(void)
{
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();
	return (0);
}