/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:49 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:50 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery", 145, 137), _target("unknown") {
	std::cout << CYNB "ShrubberyCreationForm was created!" NC << " Target is ";
	std::cout << this->_target << "." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	: AForm("Shrubbery", 145, 137), _target(target) {
	std::cout << CYNB "ShrubberyCreationForm was created!" NC << " Target is ";
	std::cout << this->_target << "." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) {
	std::cout << CYNB "Copy ShrubberyCreationForm" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	// std::cout << REDB "ShrubberyCreationForm with a target " NC;
	// std::cout << this->_target << REDB " was torn apart!" NC;
	// std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	std::cout << CYN "Assigning ShrubberyCreationForm" NC << std::endl;
	if (this != &rhs)
		*((std::string*)(&this->_target)) = rhs._target;
	return (*this);
}

//	OTHERS
std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

void		ShrubberyCreationForm::formAction(void) const {
	std::ofstream	output;

	output.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⡀⡀⠀⠀⡐⡀⠀⠀⠀⠠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀⠢⡉⠄⠀⠐⠍⠂⠀⠀⢂⡄⠀⠀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠻⠃⠸⠃⢠⠄⡀⠛⠀⡤⢀⠀⠛⠇⡀⡜⡠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⢐⣄⠠⡀⠭⢠⠀⠁⠨⠼⠀⠀⠁⠥⠇⠀⡐⡁⠀⠡⡋⠄⢠⠀⢾⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⢀⡀⠀⠈⠋⠃⠈⠈⠉⠐⢅⢲⠄⡘⡤⡰⣢⠐⡀⠷⠥⠀⠀⡠⠀⢦⡡⠙⢉⠔⣰⠂⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠈⢜⠶⣱⠸⣷⡄⢠⡟⡄⠈⠑⠊⠀⠈⠒⠓⠀⢧⢀⢔⣩⠰⣍⢆⠣⠮⠁⠦⡟⠆⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠈⠖⣦⢤⠄⠈⠑⡄⡬⣀⠘⢼⠻⢀⣤⢰⡀⠣⣫⢝⢦⢸⠪⢾⠒⡈⠾⢑⣠⠖⠴⣦⡔⡲⠂⡠⢶⠀⠀⠀⠀\n";
	output << "⠀⠈⠒⠃⠃⢲⡤⡘⠩⠳⠅⠀⢐⣷⡎⠘⠯⠂⠈⢤⣅⣸⡁⡴⣫⡇⢠⡞⣡⣀⣬⡱⠌⠀⠰⡵⣿⠀⠀⠀⠀\n";
	output << "⠀⠀⣀⣀⣀⠀⢩⣁⠸⣶⡆⡇⠈⠊⣁⠄⢛⣯⡳⠆⢠⣿⠀⠟⢳⣷⡟⡀⠻⠼⠖⠋⠀⠀⣀⠁⣥⢾⠀⠀⠀\n";
	output << "⠀⠀⠈⠛⣗⠧⠀⣙⣃⣀⡀⢰⡀⣾⣿⠀⣀⠈⠉⣰⣿⣿⠶⠖⠛⠋⠸⣟⣟⡶⠂⢀⢀⣾⣭⠸⡝⡿⠀⠀⠀\n";
	output << "⠀⣠⢖⡠⠀⠂⣩⣤⡌⠈⠙⢿⣷⡈⢠⣿⡏⠀⠀⣿⣿⠁⣀⠻⠟⠀⣠⡄⠀⢀⣶⣏⠘⠯⠟⠀⠀⣶⡶⣶⠆\n";
	output << "⠾⠿⠛⠁⠠⠾⠿⠟⠁⣴⣶⡆⠹⣿⣮⡈⠀⠀⠰⣿⡏⠘⠛⠋⠀⣼⢿⡇⠀⠸⢟⠞⠀⣀⢔⣤⣤⣝⡋⠁⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠚⠛⠙⠀⠀⠈⠻⣿⣶⣦⣴⣿⡇⠀⠀⠀⠀⣘⣾⣥⣤⡤⠶⠞⣋⣄⡐⠻⠽⠊⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢻⣿⣷⣄⣤⣶⠿⠋⠁⠀⢰⣽⣶⣄⠻⢿⡿⠶⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⡟⠁⠀⠀⠀⠀⠀⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠛⠛⠛⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	output.close();
	return ;
}
