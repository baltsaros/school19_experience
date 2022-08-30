/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:14 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 14:22:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iomanip>

int	main(void) {
	Data		*test = new Data;
	uintptr_t	uptr;

	uptr = test->serialize(test);	
	std::cout << "before: " << test << std::endl;
	std::cout << "serialization: " << uptr << std::endl;
	std::cout << "deserialization: " << test->deserialize(uptr) << std::endl;

	delete test;
	return (0);
}