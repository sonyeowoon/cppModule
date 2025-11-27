#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
private:
	int					raw;
	static const int	bits;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
