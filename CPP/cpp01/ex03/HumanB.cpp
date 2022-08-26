/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:38 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:42:39 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int	HumanB::_check = 0;

HumanB::HumanB(std::string name): _name(name){
	std::cout << this->_name << " is looking for a fight" << std::endl;
	return ;
}

HumanB::~HumanB(void){
	std::cout << this->_name << " calms down\n";
	return ;
}

void	HumanB::attack(void){
	if (this->_check == 0){
		std::cout << this->_name << " attacks with their bare hands\n";
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
	this->_check++;
	return ;
}
