/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:35:13 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:35:14 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
	private:
		std::string	_type;
		Brain*		_brains;

	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Dog&		operator=(Dog const &rhs);
		void		makeSound(void) const;
		void		getIdea(int i);
};

#endif