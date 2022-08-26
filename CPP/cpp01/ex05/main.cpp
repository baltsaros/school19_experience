/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:43:18 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 10:30:46 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define REDB "\e[41m"

int	main(void){
	Harl	customer;

	std::cout << "TESTING!" << std::endl;
	std::cout << std::endl;


	std::cout << "Level: " << RED "debug" NC << std::endl;
	customer.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "Level: " << RED "info" NC << std::endl;
	customer.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "Level: " <<  RED "warning" NC << std::endl;
	customer.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "Level: " <<  RED "error" NC << std::endl;
	customer.complain("ERROR");
	std::cout << std::endl;
	
	std::cout << "Level: " <<  RED "unknown" NC << std::endl;
	customer.complain("UUU");
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}
