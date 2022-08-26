/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:08 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:54:16 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define NC "\e[0m"
#define YLWB "\e[1;33m"

int	main(void){
	std::cout << std::endl;
	std::cout << YLWB "zombieHorde func:\n" NC;
	Zombie	*z2;
	z2 = zombieHorde(5, "Steve");
	for (int i= 0; i < 5; i++){
		std::cout << "[" << i << "]";
		z2[i].announce();
	}
	delete [] z2;
	return (0);
}
