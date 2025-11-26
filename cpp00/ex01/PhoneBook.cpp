#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : count(0), next(0) {}

int	PhoneBook::size() const { return count; }

std::string 
