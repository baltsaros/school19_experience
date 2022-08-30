/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:34:48 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:46:14 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class	WrongCat: public	WrongAnimal {
	private:
		std::string	_type;

	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat(void);

		WrongCat&	operator=(WrongCat const &rhs);
		void		makeSound(void) const;
};

#endif