/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:12 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:42:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
	return ;
}

void	Zombie::setName(std::string name){
	this->_name = name;
	return ;
}

Zombie::~Zombie(void){
	std::cout << this->_name << ": is no more\n";
	return ;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
