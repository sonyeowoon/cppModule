#include "Contact.hpp"

Contact::Contact() {}

void	Contact::setFirstName(const std::string& s) { firstName_ = s; }
void	Contact::setLastName(const std::string& s) { lastName_ = s; }
void	Contact::setNickname(const std::string& s) { nickname_ = s; }
void	Contact::setPhoneNumber(const std::string& s) { phoneNumber_ = s; }
void	Contact::setSecret(const std::string& s) { secret_ = s; }

const std::string&	Contact::firstName() const { return firstName_; }
const std::string&	Contact::lastName() const { return lastName_; }
const std::string&	Contact::nickname() const { return nickname_; }
const std::string&	Contact::phoneNumber() const { return phoneNumber_; }
const std::string&	Contact::secret() const { return secret_; }
