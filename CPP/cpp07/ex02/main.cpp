/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:19:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 10:31:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << YLWB "+++ Standard tests +++" NC << std::endl;
	Array<int, size_t> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int, size_t> tmp = numbers;
		Array<int, size_t> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	std::cout << std::endl;

	std::cout << YLWB "+++ More tests +++" NC << std::endl;
	std::cout << YLWB "Zero size" NC << std::endl;
	Array<int, int>	ar(0);
	std::cout << "size of ar is " << ar.size() << std::endl;
	std::cout << std::endl;
	std::cout << YLWB "Int array" NC << std::endl;
	Array<int, int>	ar1(10);
	for (int i = 0; i < 10; ++i) {
		ar1[i] = i + 1;
		std::cout << "ar[" << i << "]: " << ar1[i] << std::endl;
	}
	std::cout << "array is " << ar1 << std::endl;
	std::cout << std::endl;
	std::cout << YLWB "Char *" NC << std::endl;
	Array<char, size_t>	ar2(10);
	for (int i = 0; i < 10; i++) {
		ar2[i] = 97 + i;
		std::cout << "ar[" << i << "]: " << ar2[i] << std::endl;
	}
	std::cout << "array is " << ar2 << std::endl;
	std::cout << std::endl;
	std::cout << YLWB "String *" NC << std::endl;
	Array<std::string, int>	ar3(10);
	for (int i = 0; i < 10; i++) {
		ar3[i] = "test";
		std::cout << "ar[" << i << "]: " << ar3[i] << std::endl;
	}
	std::cout << "array is " << ar3 << std::endl;
	std::cout << std::endl;
	std::cout << YLWB "Float array" NC << std::endl;
	Array<float, int>	ar4(10);
	for (int i = 0; i < 10; i++) {
		ar4[i] = 4.20f + i;
		std::cout << "ar[" << i << "]: " << ar4[i] << std::endl;
	}
	std::cout << std::endl;
	return 0;
}