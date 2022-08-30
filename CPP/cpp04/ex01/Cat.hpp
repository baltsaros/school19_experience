/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:35:08 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:55:32 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public	Animal {
	private:
		std::string	_type;
		Brain*		_brains;

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat&		operator=(Cat const &rhs);
		void		makeSound(void) const;
		void		getIdea(int i);
};

#endif