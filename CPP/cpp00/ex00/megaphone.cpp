/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:11:07 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/12 10:11:08 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv){
	size_t	i;
	size_t	j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else{
		while (argv[i]){
			j = 0;
			while (argv[i][j]){
				argv[i][j] = std::toupper(argv[i][j]);
				++j;
			}
			std::cout << argv[i];
			++i;
		}
		std::cout << std::endl;
	}
	return (0);
}
