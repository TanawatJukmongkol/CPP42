/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tanawat J. <66011255@kmitl.ac.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:21:02 by Tanawat J.        #+#    #+#             */
/*   Updated: 2023/11/28 15:02:01 by Tanawat J.       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& trname)
{
	std::cout << "Clap trap " << trname << " constructor called." << std::endl;
	if (name == trname)
		return ;
	name = trname;
	this->init(10, 10, 0);
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called." << std::endl;
};

void ClapTrap::init(unsigned int hp, unsigned int energy, unsigned int atk_dmg)
{
	this->hp = hp;
	this->energy = energy;
	this->atk_dmg = atk_dmg;
}

void ClapTrap::attack(const std::string& target)
{
	if (hp == 0)
	{
		std::cout << name
				  << " iz ded. Okay?? Cannot attack." << std::endl;
		return ;
	}
	if (energy == 0)
	{
		std::cout << name
				  << ": Beep boop. I'm out of energy." << std::endl;
		return ;
	}
	energy--;
	std::cout << "ClapTrap "
			  << name
			  << " clapped "
			  << target
			  << " with "
			  << atk_dmg
			  << " Newtons of force! ("
			  << energy
			  << "pt energy left)"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << name
				  << " iz ded. Okay?? Cannot beat a dead *ahem* ClapTrap." << std::endl;
		return ;
	}
	if (hp > amount)
		hp -= amount;
	else
		hp = 0;
	std::cout << name
			  << " got bonkaied with damage of "
			  << amount
			  << "! 痛い！("
			  << hp
			  << "HP left)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout << name
				  << " iz ded. Okay?? Cannot be repaired!" << std::endl;
		return ;
	}
	if (energy == 0)
	{
		std::cout << name
				  << ": T^T. I'm out of energy. Cannot repair! ~Dori-me" << std::endl;
		return ;
	}
	hp += amount;
	energy--;
	std::cout << name
			  << " repaired thy owne health bi "
			  << amount
			  << " HP! ("
			  << hp
			  << " HP, "
			  << energy
			  << "pt energy left)" << std::endl;
}

