
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

		int		getRawBits() const;
		void	setRawBits(const int raw_bit);
		int		toInt() const;
		float	toFloat() const;
	private:
		int					raw_val;
		static const int	frac_bit = 8;
		static const int	precision = 1;
		// More precision = less number range (10e1 is recommended)
};

std::ostream & operator << (std::ostream &stdout, const Fixed &fixed);

#endif

