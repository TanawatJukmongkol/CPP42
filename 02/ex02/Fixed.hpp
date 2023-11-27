
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed ();
		Fixed (const int nbr);
		Fixed (const float nbr);
		~Fixed ();
		Fixed (Fixed &fixed); 
		Fixed &operator=(const Fixed &fixed);
		bool operator<(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator>(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		int		getRawBits();
		void	setRawBits(int raw_bit);
		int		toInt() const;
		float	toFloat() const;
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					raw_val;
		static const int	frac_bit = 8;
		static const int	precision = 1;
		// More precision = less number range (10e1 is recommended)
};

std::ostream & operator << (std::ostream &stdout, const Fixed &fixed);

#endif

