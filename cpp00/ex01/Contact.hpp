#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string phoneNumber_;
	std::string secret_;

public:
	Contact();

	void	setFirstName(const std::string& s);
	void	setLastName(const std::string& s);
	void	setNickname(const std::string& s);
	void	setPhoneNumber(const std::string& s);
	void	setSecret(const std::string& s);

	const std::string&	firstName() const;
	const std::string&	lastName() const;
	const std::string&	nickname() const;
	const std::string&	phoneNumber() const;
	const std::string&	secret() const;
};

#endif
