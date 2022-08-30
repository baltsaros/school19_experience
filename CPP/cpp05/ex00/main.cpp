/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:52:48 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 11:01:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "Case: normal rank" << std::endl;
	try {
		Bureaucrat	bur("Bob", 45);
		std::cout << bur;
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Case: rank too low to decrement" << std::endl;
	try {
		Bureaucrat	bur("Jim", 150);
		std::cout << bur;
		bur.decrement();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Case: rank too high to incremenet" << std::endl;
	try {
		Bureaucrat	bur("Karen", 1);
		std::cout << bur;
		bur.increment();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Case: negative rank" << std::endl;
	try {
		Bureaucrat	bur("Tom", -1);
		std::cout << bur;
		bur.increment();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Case: rank over 150" << std::endl;
	try {
		Bureaucrat	bur("Alice", 999);
		std::cout << bur;
		bur.increment();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
