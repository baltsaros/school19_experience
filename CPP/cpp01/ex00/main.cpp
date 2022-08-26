/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:41:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:54:47 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define NC "\e[0m"
#define YLWB "\e[1;33m"

int	main(void){
	std::cout << YLWB "standard call:\n" NC;
	Zombie	z1("Al");
	z1.announce();

	std::cout << std::endl;
	std::cout << YLWB "newZombie func:\n" NC;
	Zombie	*z2;
	z2 = newZombie("Bo");
	z2->announce();

	std::cout << std::endl;
	std::cout << YLWB "randomChump func:\n" NC;
	randomChump("Ci");

	delete z2;
	return (0);
}
