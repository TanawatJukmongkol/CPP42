/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:24 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/25 14:51:33 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
	
int main ()
{
	Fixed	fix_1;

	fix_1.setRawBits(123);
	Fixed	fix_2(fix_1);
	Fixed	fix_3;

	fix_3 = fix_2;
	std::cout << "raw bits: " << fix_3.getRawBits() << std::endl;
	return 0;
}
