#include "Span.hpp"

//	CONSTRUCTORS
template <typename T>
Span<T>::Span(void) {
	// std::cout << GRNB "Span" NC << std::endl;
	return ;
}

template <typename T>
Span<T>::Span(unsigned int N) : _N(N) {
	// std::cout << GRNB "Span" NC << std::endl;
	std::vector<T>	vct;
	this->_cntr = vct;
	return ;
}

template <typename T>
Span<T>::Span(Span<T> const &src) {
	// std::cout << GRNB "Copy Span" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
template <typename T>
Span<T>::~Span(void) {
	// std::cout << REDB "UnSpan" NC << std::endl;
	return ;
}

//	OPERATORS
template <typename T>
Span<T>&	Span<T>::operator=(Span<T> const &rhs) {
	// std::cout << GRN "Assigning Span" NC << std::endl;
	if (this != &rhs) {
		this->_N= rhs._N;
		this->_cntr= rhs._cntr;
	}
	return (*this);
}

template <typename T>
T&	Span<T>::operator[](long const i) {
	if (i < 0 || static_cast<unsigned int>(i) >= this->_cntr.size())
		throw(outOfRange());
	return (this->_cntr[i]);
}

//	OTHERS
template <typename T>
void	Span<T>::addNumber(T num) {
	if (this->_cntr.size() >= this->_N)
		throw(noSpaceLeft());
	this->_cntr.push_back(num);
	return ;
}

template <typename T>
T	Span<T>::shortestSpan(void) {
	unsigned int	size = this->_cntr.size();

	if (size == 0)
		throw(emptyCntr());
	else if (size == 1)
		throw(noSpan());

	T				min;
	std::vector<T>	tmp = this->_cntr;

	std::sort (tmp.begin(), tmp.end());
	size -= 1;
	min = tmp[size] - tmp[size - 1];
	for (unsigned i = size; i > 0; i--) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

template <typename T>
T	Span<T>::longestSpan(void) {
	unsigned int	size = this->_cntr.size();

	if (size == 0)
		throw(emptyCntr());
	else if (size == 1)
		throw(noSpan());
	T	min = *std::min_element(this->_cntr.begin(), this->_cntr.end());
	T	max = *std::max_element(this->_cntr.begin(), this->_cntr.end());
	return (max - min);
}

template <typename T>
unsigned int	Span<T>::getSize(void) {
	return (this->_cntr.size());
}

template <typename T>
std::ostream &	operator<<(std::ostream & o, Span<T> & sp) {
	unsigned int	size;

	size = sp.getSize();
	if (!size)
		o << "The container is empty!\n";
	for (unsigned int i = 0; i < size; i++) {
		o << sp[i];
		if (i < size - 1)
			o << ", ";
		else
			o << std::endl;
	}
	return (o);
}

//	EXCEPTIONS
template <typename T>
const char*	Span<T>::noSpaceLeft::what(void) const throw() {
	return (REDL "The container is full!" NC);
}

template <typename T>
const char*	Span<T>::emptyCntr::what(void) const throw() {
	return (REDL "There are no elements in the container!" NC);
}

template <typename T>
const char*	Span<T>::noSpan::what(void) const throw() {
	return (REDL "There is only one element in the container!" NC);
}

template <typename T>
const char*	Span<T>::outOfRange::what(void) const throw() {
	return (REDL "The index is out of range!" NC);
}
