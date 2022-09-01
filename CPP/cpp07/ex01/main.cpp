/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:19:31 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 10:19:32 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	elem_print(T elem) {
	std::cout << elem << std::endl;
	return ;
}

int	main(void) {
	int			array[10];
	std::string	tab[10];

	for (int i = 0; i < 10; i++)
		array[i] = i + 1;
	for (int i = 0; i < 10; i++)
		tab[i] = "test";
	std::cout << YLWB "Testing int array with size_t counter\n" NC;
	iter<int, size_t>(array, 10, &elem_print);
	std::cout << std::endl;

	std::cout << YLWB "Testing string array with int counter\n" NC;
	iter<std::string, int>(tab, 10, &elem_print);
	std::cout << std::endl;
	return (0);
}