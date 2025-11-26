#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string numbers;
	std::string secret;

public:
	Contact();

	void	setFirstName(const std::string& s);
	void	setLastName(const std::string& s);
	void	setNickname(const std::string& s);
	void	setPhoneNumber(const std::string& s);
	void	setSecret(const std::string& s);
}

#endif
