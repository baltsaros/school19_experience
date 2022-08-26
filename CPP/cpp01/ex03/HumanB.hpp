/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:41 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:42:42 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB{
	private:
		std::string	_name;
		Weapon		*_weapon;
		static int	_check;

	public:
		HumanB(std::string name);
		~HumanB(void);
		
		void		attack(void);
		void		setWeapon(Weapon &weapon);
};

#endif