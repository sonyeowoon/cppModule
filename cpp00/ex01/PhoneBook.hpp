#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class	PhoneBook {
private:
	Contact	contacts[8];
	int		cnt;
	int		next;

public:
	PhoneBook();

	void	addPB();
	void	searchPB() const;
	void	showByIndex(int idx) const;

	int		size() const;
};

std::string	inputData(const std::string& label);
std::string	fitWidth(const std::string& s);

#endif
