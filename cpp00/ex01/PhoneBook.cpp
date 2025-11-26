#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), next(0) {}

int	PhoneBook::size() const { return count; }

std::string	inputData(const std::string& label) {
	std::string line;

	while (true) {
		std::cout << label;
		if (!std::getline(std::cin, line)) 
			return std::string();
		std::string::size_type b = line.find_first_not_of(" \t\r\n");
		std::string::size_type e = line.find_last_not_of(" \t\r\n");
		if (b != std::string::npos) line = line.substr(b, e - b + 1);
		else line = "";
		if (!line.empty()) return line;
		std::cout << "Empty is not allowed. Try again." << std::endl;
	}
}

void	PhoneBook::addPB() {
	Contact	c;
	std::string	s;

	s = inputData("First name: "); if (s.empty()) return ; c.setFirstName(s);
	s = inputData("Last name: "); if (s.empty()) return ; c.setLastName(s);
	s = inputData("Nickname: "); if (s.empty()) return ; c.setNickname(s);
	s = inputData("Phone number: "); if (s.empty()) return ; c.setPhoneNumber(s);
	s = inputData("Darkest secret: "); if (s.empty()) return ; c.setSecret(s);

	contacts[next] = c;
	next = (next + 1) % 8;
	if (count < 8)
		++count;
	std::cout << "Saved." << std::endl;
}

std::string fitWidth(const std::string& s) {
	if (s.size() <= 10) return s;
	return s.substr(0, 9) + ".";
}

void	PhoneBook::searchPB() const {
	std::cout	<< std::setw(10) << "index" << "|"
				<< std::setw(10) << "first name" << "|"
				<< std::setw(10) << "last name" << "|"
				<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout	<< std::setw(10) << i << "|"
					<< std::setw(10) << fitWidth(contacts[i].firstName()) << "|"
					<< std::setw(10) << fitWidth(contacts[i].lastName()) << "|"
					<< std::setw(10) << fitWidth(contacts[i].nickname()) << std::endl;
	}
}

void	PhoneBook::showByIndex(int idx) const {
	if (idx < 0 || idx >= count) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	const Contact& c = contacts[idx];
	std::cout << "First name: "	<< c.firstName()	<< std::endl;
	std::cout << "Last name: "	<< c.lastName()	<< std::endl;
	std::cout << "Nickname: "	<< c.nickname()	<< std::endl;
	std::cout << "Phone number: "	<< c.phoneNumber()	<< std::endl;
	std::cout << "Darkest secret: "	<< c.secret()	<< std::endl;
}
