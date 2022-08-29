/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:34:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:34:27 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Cat: public	Animal {
	private:
		std::string	_type;

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat&		operator=(Cat const &rhs);
		void		makeSound(void) const;
};

#endif