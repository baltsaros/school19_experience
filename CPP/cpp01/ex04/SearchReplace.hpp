/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchReplace.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:43:04 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 10:01:57 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHREPLACE_HPP
# define SEARCHREPLACE_HPP

# include <iostream>
# include <string>
# include <fstream>

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

class	SearchReplace{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;

	public:
		SearchReplace(std::string filename, std::string s1, std::string s2);
		~SearchReplace(void);

		int	ftReplace(std::string *read);
		int	openReplace(void);
};

#endif