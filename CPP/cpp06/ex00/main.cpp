/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:23 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 14:27:30 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: Invalid amount of arguments" << std::endl;
		return (1);
	}
	try {
		Convertor	in(argv[1]);

		std::cout << in;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}