/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:19:31 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 14:11:43 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	elem_print(T elem) {
	std::cout << elem << std::endl;
	return ;
}

int	main(void) {
	int			array[10];
	std::string	tab[10];

	for (int i = 0; i < 10; i++)
		array[i] = i + 1;
	for (int i = 0; i < 10; i++)
		tab[i] = "test";
	std::cout << YLWB "Testing int array with size_t counter\n" NC;
	iter<int, size_t>(array, 10, &elem_print);
	std::cout << std::endl;

	std::cout << YLWB "Testing string array with int counter\n" NC;
	iter<std::string, int>(tab, 10, &elem_print);
	std::cout << std::endl;
	return (0);
}

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };
// std::ostream&	operator<<(std::ostream& o, Awesome const & bob) {
// 	o << YLWB "Awesome: " NC << bob.get() << std::endl;
// 	return (o);
// }

// template <typename T>
// void print( T x ) { std::cout << x << std::endl; return; }

// int main() {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // );
// 	Awesome*	as = new Awesome [5];
	
// 	iter<int, size_t>( tab, 5, &print );
// 	iter<Awesome, size_t>( as, 5, &print );

// 	return 0;
// }
