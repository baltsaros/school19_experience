#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define NC "\e[0m"
# define GRNB "\e[1;32m"
# define GRN "\e[0;32m"
# define RED "\e[0;31m"
# define REDB "\e[1;31m"
# define REDL "\e[41m"
# define CYN "\e[0;36m"
# define CYNB "\e[1;36m"
# define YLW "\e[0;33m"
# define YLWB "\e[1;33m"
# define PRPL "\e[0;35m"
# define PRPLB "\e[1;35m"
# define WHT "\e[0;37m"
# define WHTB "\e[1;37m"
# define WHTL "\e[37m"
# define BLUE "\e[0;34m"
# define BLUEB "\e[1;34m"
# define BLUEL "\e[34m"

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack: public std::stack<T> {
	private:

	public:
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void) : std::stack<T>() {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {};
		virtual ~MutantStack(void) {};

		MutantStack&	operator=(MutantStack const &rhs) {
			if (*this != rhs)
				std::stack<T>::operator=(rhs);
			return (*this); 
		};
		iterator					begin(void) { return std::stack<T>::c.begin(); }
		iterator					end(void) { return std::stack<T>::c.end(); }
		const_iterator				cbegin(void) const { return std::stack<T>::c.cbegin(); }
		const_iterator				cend(void) const { return std::stack<T>::c.cend(); }
		reverse_iterator			rbegin(void) { return std::stack<T>::c.rbegin(); }
		reverse_iterator			rend(void) { return std::stack<T>::c.rend(); }
		const_reverse_iterator		crbegin(void) const { return std::stack<T>::c.crbegin(); }
		const_reverse_iterator		crend(void) const { return std::stack<T>::c.crend(); }
};

#endif

/*
template<typename T, typename Container = std::deque<T>>
class iterable_stack
: public std::stack<T, Container>
{
    using std::stack<T, Container>::c;

public:

    // expose just the iterators of the underlying container
    auto begin() { return std::begin(c); }
    auto end() { return std::end(c); }

    auto begin() const { return std::begin(c); }
    auto end() const { return std::end(c); }
};
*/