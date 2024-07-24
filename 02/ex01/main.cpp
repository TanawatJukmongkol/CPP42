/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:24 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/27 00:09:05 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
	
int main ()
{
	Fixed	fix_1;
	Fixed	fix_2(10);
	Fixed	fix_3(42.42f);
	Fixed	fix_4(fix_2);

	fix_1 = Fixed(1234.4321f);

	std::cout << "fix_1 is: " << fix_1 << std::endl;
	std::cout << "fix_2 is: " << fix_2 << std::endl;
	std::cout << "fix_3 is: " << fix_3 << std::endl;
	std::cout << "fix_4 is: " << fix_4 << std::endl;

	std::cout << ".toInt() test:" << std::endl;
	std::cout << "fix_1 is: " << fix_1.toInt() << std::endl;
	std::cout << "fix_2 is: " << fix_2.toInt() << std::endl;
	std::cout << "fix_3 is: " << fix_3.toInt() << std::endl;
	std::cout << "fix_4 is: " << fix_4.toInt() << std::endl;

	return 0;
}
