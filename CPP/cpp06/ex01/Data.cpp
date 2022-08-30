/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:20 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 14:22:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

//	CONSTRUCTORS
Data::Data(void) {
	// std::cout << GRNB "Data" NC << std::endl;
	return ;
}

Data::Data(Data const &src) {
	// std::cout << GRNB "Copy Data" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Data::~Data(void) {
	// std::cout << REDB "UnData" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Data&	Data::operator=(Data const &rhs) {
	// std::cout << GRN "Assigning Data" NC << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

//	OTHERS
uintptr_t	Data::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Data::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}