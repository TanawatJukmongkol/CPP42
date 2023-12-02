/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:24 by tjukmong          #+#    #+#             */
/*   Updated: 2023/11/28 07:16:50 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main ()
{
	ScavTrap	scav_1("Somsee");
	ScavTrap	scav_2("Somchai");

	scav_2.guardGate();
	scav_1.attack("Somchai");
	return 0;
}
