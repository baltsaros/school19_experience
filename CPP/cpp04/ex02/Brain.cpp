/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:10 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:36:11 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//	CONSTRUCTORS
Brain::Brain(void) {
	std::cout << WHTB "Brain!" NC << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "empty";
	return ;
}

Brain::Brain(Brain const &src) {
	std::cout << WHTB "Copy Brain" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Brain::~Brain(void) {
	std::cout << WHTB "Brain" NC << REDB " dried out..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Brain&	Brain::operator=(Brain const &rhs) {
	std::cout << PRPL "Assigning Brain" NC << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i ++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

//	OTHERS
void	Brain::getIdea(int i) {
	if (i >= 0 && i < 100)
		std::cout << "My idea is " << this->_ideas[i] << std::endl;
	else
		std::cout << "There is no such an idead :(" << std::endl;
	return ;
}
