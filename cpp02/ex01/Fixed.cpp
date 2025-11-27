#include "Fixed.hpp"
#include <cmath>

const int	Fixed::bits = 8;

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	raw = value << bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	raw = static_cast<int>(roundf(value * (1 << bits)));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->raw = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return this->raw;
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(raw) / (1 << bits);
}

int	Fixed::toInt(void) const
{
	return raw >> bits;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return os;
}
