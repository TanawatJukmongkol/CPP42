/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanawat J. <66011255@kmitl.ac.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:33:45 by Tanawat J.        #+#    #+#             */
/*   Updated: 2023/11/30 10:15:00 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	raw_val = 0;
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

