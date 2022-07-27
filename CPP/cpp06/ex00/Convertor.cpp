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
	this->detectType();
	this->makeConversion();
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
	{
		this->_input = rhs._input;
		this->_c = rhs._c;
		this->_i = rhs._i;
		this->_f = rhs._f;
		this->_d = rhs._d;
	}
	return (*this);
}

//	OTHERS
void	Convertor::detectType(void) {
	if (_input.length() == 1 && isalpha(_input[0]))
		_c = static_cast<char>(_input[0]);
	else if (isdigit(_input[0])) {
		if (_input.find(".") && _input.find(".") != -1) {
			if (_input.find("f") && _input.find("f") != -1)
				sscanf(_input.c_str(), "%f", &_f);
			else
				sscanf(_input.c_str(), "%lf", &_d);
		}
		else
			sscanf(_input.c_str(), "%d", &_i);
	}
	else if (_input == "-inff" || _input == "+inff" || _input == "nanf")
		sscanf(_input.c_str(), "%f", &_f);
	else if (_input == "-inf" || _input == "+inf" || _input == "nan")
		sscanf(_input.c_str(), "%lf", &_d);
	else
		throw(InvalidInput());
}

void	Convertor::makeConversion(void) {
	if (this->_c) {
		this->_i = static_cast<int>(this->_c);
		this->_f = static_cast<float>(this->_c);
		this->_d = static_cast<double>(this->_c);
	}
	else if (this->_i) {
		this->_c = static_cast<char>(this->_i);
		this->_f = static_cast<float>(this->_i);
		this->_d = static_cast<double>(this->_i);
	}
	else if (this->_f) {
		this->_c = static_cast<char>(this->_f);
		this->_i = static_cast<int>(this->_f);
		this->_d = static_cast<double>(this->_f);
	}
	else if (this->_d) {
		this->_c = static_cast<char>(this->_d);
		this->_i = static_cast<int>(this->_d);
		this->_f = static_cast<float>(this->_d);
	}
}

char	Convertor::getChar(void) const {
	if (isnan(this->_d) || isinf(this->_d))
		throw(Impossible());
	else if (isnan(this->_f) || isinf(this->_f))
		throw(Impossible());
	else if (!isprint(this->_c))
		throw(NonDisplayable());
	else
		return (this->_c);
}

int	Convertor::getInt(void) const {
	if (isnan(this->_d) || isinf(this->_d))
		throw(Impossible());
	else if (isnan(this->_f) || isinf(this->_f))
		throw(Impossible());
	return (this->_i);
}

float	Convertor::getFloat(void) const {
	return (this->_f);
}

double	Convertor::getDouble(void) const {
	return (this->_d);
}

const char*	Convertor::InvalidInput::what(void) const throw() {
	return (REDL "Invalid input!" NC);
}

const char*	Convertor::NonDisplayable::what(void) const throw() {
	return (REDL "Non displayable" NC);
}

const char*	Convertor::Impossible::what(void) const throw() {
	return (REDL "impossible" NC);
}

std::ostream &	operator<<(std::ostream & o, Convertor const & in) {
	o << YLWB "Convertor" NC << " stored the following parameters:" << std::endl;
	o << "char: ";
	try {
		in.getChar();
		o << "'" << in.getChar() << "'" << std::endl;
	}
	catch (std::exception& e) {
		o << e.what() << std::endl;
	}
	try {
		o << "int: " << in.getInt() << std::endl;
	}
	catch (std::exception& e) {
		o << e.what() << std::endl;
	}
	o << std::fixed << std::setprecision(1);
	o << "float: " << in.getFloat() << "f" << std::endl;
	o << "double: " << in.getDouble() << std::endl;
	return (o);
}
