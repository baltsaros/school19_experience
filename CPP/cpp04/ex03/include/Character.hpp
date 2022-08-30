/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:39 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:54:36 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Character : public ICharacter {
	private:
		std::string			_name;
		AMateria*			_inventory[4];

	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const &src);
		~Character(void);

		Character&			operator=(Character const &rhs);
		std::string const &	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				showEquip(void) const;
};

#endif
