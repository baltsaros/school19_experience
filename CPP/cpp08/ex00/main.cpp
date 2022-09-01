/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:03:53 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 11:03:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"

int	main(void) {
	std::cout << YLWB "+++ Testing int array +++" NC << std::endl;
	try {
	std::array<int, 4>	ar = {11, 22, 33, 44};
	int	*f;
	int	tofind;

	std::cout << "Array: ";
	for (int i = 0; i < 4; i++) {
		std::cout << ar[i];
		if (i < 3)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
	tofind = 44;
	std::cout << "To find: " << tofind << std::endl;
	std::cout << "Found: ";
	f = easyfind(ar, tofind);
	std::cout << *f << std::endl;
	tofind = 55;
	std::cout << "To find: " << tofind << std::endl;
	std::cout << "Found: ";
	f = easyfind(ar, tofind);
	std::cout << *f << std::endl;
	std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << YLWB "+++ Testing int vector +++" NC << std::endl;
	try {
	std::vector<int>			vct;
	std::vector<int>::iterator	f;
	int							tofind;

	for (int i = 0; i < 4; i++) {
		vct.push_back(i + 1);
	}
	std::cout << "Vector: ";
	for (int i = 0; i < 4; i++) {
		std::cout << vct[i];
		if (i < 3)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
	tofind = 3;
	std::cout << "To find: " << tofind << std::endl;
	std::cout << "Found: ";
	f = easyfind(vct, tofind);
	std::cout << *f << std::endl;
	tofind = 5;
	std::cout << "To find: " << tofind << std::endl;
	std::cout << "Found: ";
	f = easyfind(vct, tofind);
	std::cout << *f << std::endl;
	std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << YLWB "+++ Testing string list +++" NC << std::endl;
	try {
	std::list<int>				lst (5, 7);
	std::list<int>::iterator	it;
	std::list<int>::iterator	f;
	int							tofind;

	std::cout << "List: ";
	for (it = lst.begin(); it != lst.end(); it++) {
		std::cout << *it;
		if (it != lst.end())
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
	std::cout << std::endl;
	tofind = 7;
	std::cout << "To find: " << tofind << std::endl;
	std::cout << "Found: ";
	f = easyfind(lst, tofind);
	std::cout << *f << std::endl;
	tofind = 5;
	std::cout << "To find: " << tofind << std::endl;
	std::cout << "Found: ";
	f = easyfind(lst, tofind);
	std::cout << *f << std::endl;
	std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}