/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:50 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:42:51 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon){
	this->_type = weapon;
	return ;
}

std::string const &	Weapon::getType(void) const{
	return (this->_type);
}

void	Weapon::setType(std::string weapon){
	this->_type = weapon;
	return ;
}