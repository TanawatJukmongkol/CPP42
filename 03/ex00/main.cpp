/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:24 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/28 07:14:06 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	ClapTrap	trap1("Joe");
	ClapTrap	trap2("Bob");

	for (int i = 0; i < 11; i++)
	{
		std::cout << "-- turn " << i + 1 << " --" << std::endl;
		trap1.attack("Bob");
		trap2.takeDamage(2);
		trap2.beRepaired(((i + 1) % 2) + 1);

		trap2.attack("Joe");
		trap1.takeDamage(2);
		trap1.beRepaired(1 + (i % 4));
	}
	return 0;
}
