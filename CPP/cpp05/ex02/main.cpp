/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:56 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 11:11:42 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int	main(void) {
	std::cout << std::endl;
	std::cout << "Case: ShrubberyCreationForm normal" << std::endl;
	try {
		ShrubberyCreationForm	shrub("home");
		Bureaucrat				bur1("Jovanni", 3);
		Bureaucrat				bur2("Tom", 13);

		std::cout << shrub;
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(shrub);
		bur2.executeForm(shrub);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: RobotomyRequestForm normal" << std::endl;
	try {
		RobotomyRequestForm		robotomy("Cat");
		Bureaucrat				bur1("Sarah", 3);

		std::cout << robotomy;
		std::cout << bur1;
		bur1.signForm(robotomy);
		bur1.executeForm(robotomy);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: PresidentialPardonForm too low to execute" << std::endl;
	try {
		PresidentialPardonForm	form("Urmom");
		Bureaucrat				bur1("Bev", 2);
		Bureaucrat				bur2("Bath", 6);

		std::cout << form;
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(form);
		bur2.executeForm(form);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Case: PresidentialPardonForm too low to sign" << std::endl;
	try {
		PresidentialPardonForm	form("Umom");
		Bureaucrat				bur1("Bev", 28);
		Bureaucrat				bur2("Bath", 1);

		std::cout << form;
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(form);
		bur2.executeForm(form);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Case: ShrubberyCreationForm, not signed" << std::endl;
	try {
		ShrubberyCreationForm	shrub("work");
		Bureaucrat				bur("Sui", 3);

		std::cout << shrub;
		std::cout << bur;
		bur.executeForm(shrub);
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
