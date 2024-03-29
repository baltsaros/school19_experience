/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:54:05 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 11:05:42 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	std::cout << std::endl;
	std::cout << "Case: normal rank" << std::endl;
	try {
		Form	form1("Un", 45, 70);

		std::cout << form1;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: too low rank" << std::endl;
	try {
		Form	form2("Deux", 150, 170);

		std::cout << form2;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: too high rank" << std::endl;
	try {
		Form	form3("Trois", -11, 1);

		std::cout << form3;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: low bureaucrat and high form" << std::endl;
	try {
		Bureaucrat	bur("Tom", 75);
		Form		form3("Quatre", 45, 75);

		std::cout << bur;
		std::cout << form3;
		bur.signForm(form3);
		std::cout << form3;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: high bureaucrat and low form" << std::endl;
	try {
		Bureaucrat	bur("Alice", 5);
		Form		form3("Cinq", 45, 75);

		std::cout << bur;
		std::cout << form3;
		bur.signForm(form3);
		std::cout << form3;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: similar bureaucrat and form" << std::endl;
	try {
		Bureaucrat	bur("TinTin", 35);
		Form		form3("Six", 35, 75);

		std::cout << bur;
		std::cout << form3;
		bur.signForm(form3);
		std::cout << form3;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
