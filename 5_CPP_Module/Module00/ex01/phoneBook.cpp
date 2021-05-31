#include "phoneBook.hpp"

PhoneBook::PhoneBook(void) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void PhoneBook::addData(void) {

	std::cout << "[ADD DATA]" << std::endl;
	std::cout << "first name > ";
	std::getline(std::cin, this->firstName);
	std::cout << "last name > ";
	std::getline(std::cin, this->lastName);
	std::cout << "nickname > ";
	std::getline(std::cin, this->nickname);
	std::cout << "login > ";
	std::getline(std::cin, this->login);
	std::cout << "postal address > ";
	std::getline(std::cin, this->postalAddress);
	std::cout << "email address > ";
	std::getline(std::cin, this->emailAddress);
	std::cout << "phone number > ";
	std::getline(std::cin, this->phoneNumber);
	std::cout << "birthday > ";
	std::getline(std::cin, this->birthday);
	std::cout << "favorite meal > ";
	std::getline(std::cin, this->favoriteMeal);
	std::cout << "underwear color > ";
	std::getline(std::cin, this->underwearColor);
	std::cout << "darkest secret > ";
	std::getline(std::cin, this->darkestSecret);
}

void PhoneBook::printCommon(std::string value)
{
	if (value.length() > 10)
		std::cout << '|' << value.substr(0, 9) << '.';
	else
		std::cout << '|' << std::setw(10) << value;
}

void PhoneBook::serachData(int index) {
	std::cout << '|' << std::setw(10) << index;
	printCommon(firstName);
	printCommon(lastName);
	printCommon(nickname);
	std::cout << '|' << std::endl;

}

void PhoneBook::printAllData(void) {
	std::cout << "first name: " << this->firstName << std::endl;
	std::cout << "last name: " << this->lastName << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "login: " << this->login << std::endl;
	std::cout << "postal address: " << this->postalAddress << std::endl;
	std::cout << "email address: " << this->emailAddress << std::endl;
	std::cout << "phone number: " << this->phoneNumber << std::endl;
	std::cout << "birthday: " << this->birthday << std::endl;
	std::cout << "favorite meal: " << this->favoriteMeal << std::endl;
	std::cout << "underwear color: " << this->underwearColor << std::endl;
	std::cout << "darkest secret: " << this->darkestSecret << std::endl;
}

int main()
{
	std::string cmd;
	PhoneBook books[8];
	int	bookCount = 0;
	int index;

	while (1)
	{
		std::cout << "[My PhoneBook]" << std::endl;
		std::cout << "command ADD or SEARCH or EXIT > ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		if (cmd.compare("ADD") == 0)
		{
			if (bookCount < 8)
				books[bookCount++].addData();
			else
				std::cout << "Error: Phonebook is full!" << std::endl;
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			if (bookCount == 0)
			{
				std::cout << "ERROR: Phonebook is empty" << std::endl;
				continue;
			}
			std::cout << "|==========|==========|==========|==========|" << std::endl;
			std::cout << "|     index|first name| last name|  nickname|" << std::endl;
			std::cout << "|==========|==========|==========|==========|" << std::endl;
			for (int i = 0; i < bookCount; i++)
				books[i].serachData(i);
			std::cout << "|==========|==========|==========|==========|" << std::endl;
			std::cout << "SEARCH: index > ";
			std::getline(std::cin, cmd);
			index = atoi(cmd.c_str());
			for (int i = 0; i < (int)cmd.length(); i++)
			{
				if (!isdigit(cmd[i]))
				{
					index = -1;
					break;
				}
			}
			index = (0 <= index && index < bookCount) ? index : -1;
			if (index == -1)
				std::cout << "SEARCH: wrong index!!" << std::endl;
			else
				books[index].printAllData();
		}
		else if (cmd.compare("EXIT") == 0)
		{
			std::cout << "exit" << std::endl;
			break;
		}
	}
	return (0);
}
