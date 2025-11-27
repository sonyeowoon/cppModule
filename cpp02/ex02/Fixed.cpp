#include "Fixed.hpp"
#include <cmath>

const int	Fixed::bits = 8;

Fixed::Fixed() : raw(0) {}

Fixed::Fixed(const int value) {
	raw = value << bits;
}

Fixed::Fixed(const float value) {
	raw = static_cast<int>(roundf(value * (1 << bits)));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs)
		this->raw = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int	Fixed::getRawBits(void) const {
	return this->raw;
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(raw) / (1 << bits);
}

int	Fixed::toInt(void) const {
	return raw >> bits;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return os;
}

bool	Fixed::operator>(Fixed const &rhs) const {
	return this->raw > rhs.raw;
}

bool	Fixed::operator<(Fixed const &rhs) const {
	return this->raw < rhs.raw;
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	return this->raw >= rhs.raw;
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	return this->raw <= rhs.raw;
}

bool	Fixed::operator==(Fixed const &rhs) const {
	return this->raw == rhs.raw;
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	return this->raw != rhs.raw;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
	++this->raw;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--() {
	--this->raw;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b) ? a : b;
}
