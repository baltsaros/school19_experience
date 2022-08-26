/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:57 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 10:08:26 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SearchReplace.hpp"

int	main(int argc, char **argv){
	if (argc != 4){
		std::cerr << REDL "Error: Invalid amount of arguments!" NC << std::endl;
		return (-1);
	}

	int				ret;
	SearchReplace	replacer(argv[1], argv[2], argv[3]);
	ret = replacer.openReplace();
	if (ret){
		if (ret == -2)
			std::cerr << REDL "Error: Invalid arguments!" NC << std::endl;
		else if (ret == -3)
			std::cerr << REDL "Error: Corrupted/invalid file!" NC << std::endl;
		else if (ret == -4)
			std::cerr << REDL "Error: Incorrect replacement!" NC << std::endl;
		else
			std::cerr << REDL "Damn, something went wrong!" NC << std::endl;
		return (ret);
	}
	return (0);
}
