/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanawat J. <66011255@kmitl.ac.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:33:45 by Tanawat J.        #+#    #+#             */
/*   Updated: 2023/11/30 10:19:45 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	raw_val = 0;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	raw_val = (precision * nbr) << frac_bit;
	return ;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	raw_val = roundf( (precision * nbr) * (1 << frac_bit) );
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &fixed)
{
	std::cout << "Fixed copied" << std::endl;
	raw_val = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignment copied" << std::endl;
	raw_val = fixed.raw_val;
	return *this;
}

std::ostream &operator<<(std::ostream &stdout, const Fixed &fixed)
{
	stdout << fixed.toFloat();
	return stdout;
}

void Fixed::setRawBits(const int raw_bit)
{
	std::cout << "Set raw bit" << std::endl;
	raw_val = raw_bit;
}

int Fixed::getRawBits() const
{
	std::cout << "Get raw bit" << std::endl;
	return raw_val;
}

int Fixed::toInt() const
{
	return (raw_val / (1 << frac_bit)) / precision;
}

float Fixed::toFloat() const
{
	return ((float)raw_val / (float)(1 << frac_bit)) / precision;
}

