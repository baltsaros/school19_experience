/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:43:31 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 10:34:29 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define REDB "\e[41m"
#define YLW "\e[0;33m"
#define YLWB "\e[1;33m"

int	main(int argc, char *argv[]){
	Harl	customer;

	if (argc != 2){
		std::cerr << REDB "Error: ";
		std::cerr << "Invalid amount of arguments!" NC << std::endl;
		return (-1);
	}

	std::cout << YLWB "TESTING!" NC << std::endl;
	std::cout << std::endl;

	std::cout << YLW "Your input: " NC << argv[1] << std::endl;
	customer.complain(argv[1]);
	std::cout << std::endl;
	
	std::cout << YLWB "Standard levels." NC << std::endl;

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
	
	std::cout << "Invalid level" << std::endl;
	customer.complain("toto");
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}