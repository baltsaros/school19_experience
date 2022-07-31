#include "Array.hpp"

//	CONSTRUCTORS
template <typename T>
Array::Array(void) : _size(0), _array(NULL) {
	// std::cout << GRNB "Array" NC << std::endl;
	return ;
}

template <typename T>
Array::Array(unsigned int n) : _size(n), {
	// std::cout << GRNB "Array" NC << std::endl;
	if (n)
		this->_array = new T [n];
	else
		this->_array = NULL;
	return ;
}

template <typename T>
Array::Array(Array const &src) {
	// std::cout << GRNB "Copy Array" NC << std::endl;
	// if (this->_array)
	// 	delete [] this->_array;

	// this->_size = src.size();
	// this->_array = new T [this->_size];
	// for (unsigned int i = 0; i < this->_size; i++)
	// 	this->_array[i] = src._array[i];
	*this = src;
	return ;
}

//	DESTRUCTOR
template <typename T>
Array::~Array(void) {
	// std::cout << REDB "UnArray" NC << std::endl;
	if (this->_array)
		delete [] this->_array;
	return ;
}

//	OPERATORS
template <typename T>
Array&	Array::operator=(Array const &rhs) {
	// std::cout << GRN "Assigning Array" NC << std::endl;
	if (this == &rhs)
		return (*this);
	if (this->_array)
		delete [] this->_array;
	this->_size = rhs.size();
	this->_array = new T [this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
	return (*this);
}

template <typename T, typename U>
T&	Array::operator[](U const i) {
	if (i < 0 || i > this->_size)
		throw(outOfRange());
	return (this->_array[i]);
}

//	OTHERS
template <typename T>
unsigned int	Array::size(void) {
	return (this->_size);
}

const char*	Array::outOfRange::what(void) const throw() {
	return (REDL "The index is out of range!" NC);
}