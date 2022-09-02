/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:04:06 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/02 10:40:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << YLWB "Test from the subject\n" NC;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size after pop: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}

	{
		std::cout << YLWB "Extra test: vector\n" NC;
		std::vector<int> vct;
		vct.push_back(5);
		vct.push_back(17);
		std::cout << "front elem: " << vct.front() << std::endl;
		vct.pop_back();
		std::cout << "size after pop: " << vct.size() << std::endl;
		vct.push_back(3);
		vct.push_back(5);
		vct.push_back(737);
		vct.push_back(0);
		std::vector<int>::iterator it = vct.begin();
		std::vector<int>::iterator ite = vct.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
	}

	{
		std::cout << YLWB "Extra test: list\n" NC;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "front elem: " << lst.front() << std::endl;
		lst.pop_back();
		std::cout << "size after pop: " << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
	}
	return 0;
}