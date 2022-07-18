#include "include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery", 145, 137), _target("unknown") {
	std::ofstream	output;

	output.open(this->_target + "_shrubbery", std::ofstream::out | std::ofstream::app);
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⡀⡀⠀⠀⡐⡀⠀⠀⠀⠠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀⠢⡉⠄⠀⠐⠍⠂⠀⠀⢂⡄⠀⠀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠻⠃⠸⠃⢠⠄⡀⠛⠀⡤⢀⠀⠛⠇⡀⡜⡠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⢐⣄⠠⡀⠭⢠⠀⠁⠨⠼⠀⠀⠁⠥⠇⠀⡐⡁⠀⠡⡋⠄⢠⠀⢾⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⢀⡀⠀⠈⠋⠃⠈⠈⠉⠐⢅⢲⠄⡘⡤⡰⣢⠐⡀⠷⠥⠀⠀⡠⠀⢦⡡⠙⢉⠔⣰⠂⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠈⢜⠶⣱⠸⣷⡄⢠⡟⡄⠈⠑⠊⠀⠈⠒⠓⠀⢧⢀⢔⣩⠰⣍⢆⠣⠮⠁⠦⡟⠆⠀⠀⠀⠀⠀⠀⠀";
	output << "⠈⠖⣦⢤⠄⠈⠑⡄⡬⣀⠘⢼⠻⢀⣤⢰⡀⠣⣫⢝⢦⢸⠪⢾⠒⡈⠾⢑⣠⠖⠴⣦⡔⡲⠂⡠⢶⠀⠀⠀⠀";
	output << "⠀⠈⠒⠃⠃⢲⡤⡘⠩⠳⠅⠀⢐⣷⡎⠘⠯⠂⠈⢤⣅⣸⡁⡴⣫⡇⢠⡞⣡⣀⣬⡱⠌⠀⠰⡵⣿⠀⠀⠀⠀";
	output << "⠀⠀⣀⣀⣀⠀⢩⣁⠸⣶⡆⡇⠈⠊⣁⠄⢛⣯⡳⠆⢠⣿⠀⠟⢳⣷⡟⡀⠻⠼⠖⠋⠀⠀⣀⠁⣥⢾⠀⠀⠀";
	output << "⠀⠀⠈⠛⣗⠧⠀⣙⣃⣀⡀⢰⡀⣾⣿⠀⣀⠈⠉⣰⣿⣿⠶⠖⠛⠋⠸⣟⣟⡶⠂⢀⢀⣾⣭⠸⡝⡿⠀⠀⠀";
	output << "⠀⣠⢖⡠⠀⠂⣩⣤⡌⠈⠙⢿⣷⡈⢠⣿⡏⠀⠀⣿⣿⠁⣀⠻⠟⠀⣠⡄⠀⢀⣶⣏⠘⠯⠟⠀⠀⣶⡶⣶⠆";
	output << "⠾⠿⠛⠁⠠⠾⠿⠟⠁⣴⣶⡆⠹⣿⣮⡈⠀⠀⠰⣿⡏⠘⠛⠋⠀⣼⢿⡇⠀⠸⢟⠞⠀⣀⢔⣤⣤⣝⡋⠁⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠚⠛⠙⠀⠀⠈⠻⣿⣶⣦⣴⣿⡇⠀⠀⠀⠀⣘⣾⣥⣤⡤⠶⠞⣋⣄⡐⠻⠽⠊⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢻⣿⣷⣄⣤⣶⠿⠋⠁⠀⢰⣽⣶⣄⠻⢿⡿⠶⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⡟⠁⠀⠀⠀⠀⠀⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠛⠛⠛⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output.close();
	// std::cout << CYNB "ShrubberyCreationForm was created!" NC << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	: AForm("Shrubbery", 145, 137), _target(target) {
	std::ofstream	output;

	output.open(this->_target + "_shrubbery", std::ofstream::out | std::ofstream::app);
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⡀⡀⠀⠀⡐⡀⠀⠀⠀⠠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠀⠀⠢⡉⠄⠀⠐⠍⠂⠀⠀⢂⡄⠀⠀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠻⠃⠸⠃⢠⠄⡀⠛⠀⡤⢀⠀⠛⠇⡀⡜⡠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⢐⣄⠠⡀⠭⢠⠀⠁⠨⠼⠀⠀⠁⠥⠇⠀⡐⡁⠀⠡⡋⠄⢠⠀⢾⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⢀⡀⠀⠈⠋⠃⠈⠈⠉⠐⢅⢲⠄⡘⡤⡰⣢⠐⡀⠷⠥⠀⠀⡠⠀⢦⡡⠙⢉⠔⣰⠂⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠈⢜⠶⣱⠸⣷⡄⢠⡟⡄⠈⠑⠊⠀⠈⠒⠓⠀⢧⢀⢔⣩⠰⣍⢆⠣⠮⠁⠦⡟⠆⠀⠀⠀⠀⠀⠀⠀";
	output << "⠈⠖⣦⢤⠄⠈⠑⡄⡬⣀⠘⢼⠻⢀⣤⢰⡀⠣⣫⢝⢦⢸⠪⢾⠒⡈⠾⢑⣠⠖⠴⣦⡔⡲⠂⡠⢶⠀⠀⠀⠀";
	output << "⠀⠈⠒⠃⠃⢲⡤⡘⠩⠳⠅⠀⢐⣷⡎⠘⠯⠂⠈⢤⣅⣸⡁⡴⣫⡇⢠⡞⣡⣀⣬⡱⠌⠀⠰⡵⣿⠀⠀⠀⠀";
	output << "⠀⠀⣀⣀⣀⠀⢩⣁⠸⣶⡆⡇⠈⠊⣁⠄⢛⣯⡳⠆⢠⣿⠀⠟⢳⣷⡟⡀⠻⠼⠖⠋⠀⠀⣀⠁⣥⢾⠀⠀⠀";
	output << "⠀⠀⠈⠛⣗⠧⠀⣙⣃⣀⡀⢰⡀⣾⣿⠀⣀⠈⠉⣰⣿⣿⠶⠖⠛⠋⠸⣟⣟⡶⠂⢀⢀⣾⣭⠸⡝⡿⠀⠀⠀";
	output << "⠀⣠⢖⡠⠀⠂⣩⣤⡌⠈⠙⢿⣷⡈⢠⣿⡏⠀⠀⣿⣿⠁⣀⠻⠟⠀⣠⡄⠀⢀⣶⣏⠘⠯⠟⠀⠀⣶⡶⣶⠆";
	output << "⠾⠿⠛⠁⠠⠾⠿⠟⠁⣴⣶⡆⠹⣿⣮⡈⠀⠀⠰⣿⡏⠘⠛⠋⠀⣼⢿⡇⠀⠸⢟⠞⠀⣀⢔⣤⣤⣝⡋⠁⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠚⠛⠙⠀⠀⠈⠻⣿⣶⣦⣴⣿⡇⠀⠀⠀⠀⣘⣾⣥⣤⡤⠶⠞⣋⣄⡐⠻⠽⠊⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢻⣿⣷⣄⣤⣶⠿⠋⠁⠀⢰⣽⣶⣄⠻⢿⡿⠶⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⡟⠁⠀⠀⠀⠀⠀⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠛⠛⠛⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	output.close();
	// std::cout << CYNB "ShrubberyCreationForm " NC << this->_name;
	// std::cout << CYNB " was created!" NC << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) {
	std::cout << CYNB "Copy ShrubberyCreationForm" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	// std::cout << REDB "ShrubberyCreationForm " NC << this->_name;
	// std::cout << REDB " was torn apart!" NC;
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
