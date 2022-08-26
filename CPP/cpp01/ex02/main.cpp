/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:25 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:57:07 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define NC "\e[0m"
#define YLWB "\e[1;33m"

int	main(void){
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;

	std::cout << YLWB "Printing memory address:\n" NC;
	std::cout << "str: " << &str << std::endl;
	std::cout << "ptr: " << stringPTR << std::endl;
	std::cout << "ref: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "Printing values:\n" NC;
	std::cout << "str: " << str << std::endl;
	std::cout << "ptr: " << *stringPTR << std::endl;
	std::cout << "ref: " << stringREF << std::endl;
	return (0);
}
