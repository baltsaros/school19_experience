/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:49:43 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:49:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define NC "\e[0m"
#define GRNB "\e[1;32m"
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define REDB "\e[1;31m"
#define REDL "\e[41m"
#define CYN "\e[0;36m"
#define YLW "\e[0;33m"
#define YLWB "\e[1;33m"
#define PRPL "\e[0;35m"
#define PRPLB "\e[1;35m"
#define WHT "\e[0;37m"
#define WHTB "\e[1;37m"
#define WHTL "\e[37m"
#define BLUE "\e[0;34m"
#define BLUEB "\e[1;34m"
#define BLUEL "\e[34m"

#include <iostream>
#include <string>

class	ClapTrap {
	protected:
		std::string		_name;
		int				_hp;
		int				_ep;
		unsigned int	_ad;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap&	operator=(ClapTrap const &rhs);
		void		attack(const std::string& target);
		void		attack(ClapTrap& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void);
		void		useEnergy(unsigned int amount);
		void		approach(void);
};

#endif