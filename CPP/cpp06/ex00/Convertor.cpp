#include "Convertor.hpp"

//	CONSTRUCTORS
Convertor::Convertor(void) {
	std::cout << GRNB "Default Convertor" NC << std::endl;
	this->_input = "0";
	return ;
}

Convertor::Convertor(std::string input) {
	// std::cout << GRNB "Convertor" NC << std::endl;
	this->_input = input;
	return ;
}

Convertor::Convertor(Convertor const &src) {
	// std::cout << GRNB "Copy Convertor" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Convertor::~Convertor(void) {
	// std::cout << REDB "UnConvertor" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Convertor&	Convertor::operator=(Convertor const &rhs) {
	// std::cout << GRN "Assigning Convertor" NC << std::endl;
	if (this != &rhs)
		this->_input = rhs._input;
	return (*this);
}

//	OTHERS

void	Convertor::detectType(void) {
	if (this->_input.length() == 1 && isalpha(this->_input[0]))
		this->_c = static_cast<char>(this->_input[0]);
	else if (isdigit(this->_input[0])) {
		if (this->_input.find(".") && this->_input.find(".") != -1) {
			printf("find ret is %d\n", this->_input.find("."));
			if (this->_input.find("f") && this->_input.find("f") != -1)
				sscanf(this->_input.c_str(), "%f", &this->_f);
			else
				sscanf(this->_input.c_str(), "%lf", &this->_d);
				// this->_d = static_cast<double>(this->_d);
		}
		else
			sscanf(this->_input.c_str(), "%i", &this->_i);
	}
	else
		throw(InvalidInput());
}

char	Convertor::getChar(void) const {
	if (this->_c)
		return (this->_c);
}

int	Convertor::getInt(void) const {
	if (this->_i)
		return (this->_i);
}

float	Convertor::getFloat(void) const {
	if (this->_f)
		return (this->_f);
}

double	Convertor::getDouble(void) const {
	if (this->_d)
		return (this->_d);
}

const char*	Convertor::InvalidInput::what(void) const throw() {
	return (REDL "Invalid input!" NC);
}

const char*	Convertor::ImpossibleToDisplay::what(void) const throw() {
	return (REDL "impossible to display!" NC);
}

std::ostream &	operator<<(std::ostream & o, Convertor const & in) {
	o << YLWB "Convertor" NC << " stored the following parameters:" << std::endl;
	o << "char - " << in.getChar() << std::endl;
	o << "int - " << in.getInt() << std::endl;
	o << "float - " << in.getFloat() << "f" << std::endl;
	o << "double - " << in.getDouble() << std::endl;
	return (o);
}