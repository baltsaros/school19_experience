#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

int	main(void) {
	std::cout << std::endl;
	std::cout << "Case: correct form (Presidential Pardon)" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("presidential pardon", "urmom");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Case: correct form (Robotomy Request)" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("robotomy request", "Bender");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Case: correct form (ShrubberyCreation)" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("shrubbery creation", "Home");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Case: correct form in uppercase" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("PRESIDENTIAL PARDON", "urmom");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Case: incorrect form" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("PRESIDENTIAL", "urmom");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Case: invalid target" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("PRESIDENTIAL", "");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Case: invalid form" << std::endl;
	try {
		Intern		rayn;
		AForm		*form;

		Bureaucrat	bur1("Jovanni", 3);
		Bureaucrat	bur2("Tom", 5);

		form = rayn.makeForm("", "urmom");
		std::cout << bur1;
		std::cout << bur2;
		bur1.signForm(*form);
		bur2.executeForm(*form);
		delete form;
	}
	catch (std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
