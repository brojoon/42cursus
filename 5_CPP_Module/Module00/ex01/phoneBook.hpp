#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string login;
		std::string postalAddress;
		std::string emailAddress;
		std::string phoneNumber;
		std::string birthday;
		std::string favoriteMeal;
		std::string underwearColor;
		std::string darkestSecret;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addData(void);
		void printCommon(std::string value);
		void serachData(int index);
		void printAllData(void);
};

#endif