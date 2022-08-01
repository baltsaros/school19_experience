#include <iomanip>
#include "Array.hpp"

//	CONSTRUCTORS
template <typename T, typename U>
Array<T, U>::Array(void) : _size(0), _array(NULL) {
	// std::cout << GRNB "default Array" NC << std::endl;
	return ;
}

template <typename T, typename U>
Array<T, U>::Array(unsigned int n) : _size(n) {
	// std::cout << GRNB "Array" NC << std::endl;
	if (n)
		this->_array = new T [n];
	else
		this->_array = NULL;
	return ;
}

template <typename T, typename U>
Array<T, U>::Array(Array<T, U> const &src) {
	// std::cout << GRN "Copy Array" NC << std::endl;
	this->_size = src._size;
	this->_array = new T [this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
	return ;
}

//	DESTRUCTOR
template <typename T, typename U>
Array<T, U>::~Array(void) {
	// std::cout << REDB "UnArray" NC << std::endl;
	if (this->_array)
		delete [] this->_array;
	return ;
}

//	OPERATORS
template <typename T, typename U>
Array<T, U>&	Array<T, U>::operator=(Array<T, U> const &rhs) {
	// std::cout << GRN "Assigning Array" NC << std::endl;
	if (this == &rhs)
		return (*this);
	if (this->_array) {
		delete [] this->_array;
		this->_array = NULL;
	}
	this->_size = rhs._size;
	this->_array = new T [this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = rhs._array[i];
	return (*this);
}

template <typename T, typename U>
T&	Array<T, U>::operator[](U const i) {
	if (i < 0 || static_cast<unsigned int>(i) >= this->_size)
		throw(outOfRange());
	return (this->_array[i]);
}

//	OTHERS
template <typename T, typename U>
unsigned int	Array<T, U>::size(void) const{
	return (this->_size);
}

template <typename T, typename U>
const char*	Array<T, U>::outOfRange::what(void) const throw() {
	return (REDL "The index is out of range!" NC);
}

template <typename T, typename U>
std::ostream &	operator<<(std::ostream & o, Array<T, U> & ar) {
	for (size_t i = 0; i < ar.size(); i++)
		o << ar[i];
	return (o);
}
