
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed ();
		~Fixed ();
		Fixed (Fixed &fixed); 
		Fixed &operator=(const Fixed &fixed);

		int		getRawBits() const;
		void	setRawBits(const int raw_bit);
	private:
		int					raw_val;
		static const int	frac_bit = 8;
};

#endif

