/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:03:51 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 11:03:52 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <vector>
#include <list>
#include <string>
#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &container, int n) {
	typename T::iterator	it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw(nothingFound());
	return (it);
}

const char*	nothingFound::what(void) const throw() {
	return (REDL "No occurence has been found!" NC);
}
