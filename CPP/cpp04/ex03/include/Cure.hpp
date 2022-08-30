/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:37 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:54:39 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria {
	private:
		std::string	_type;

	public:
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);

		Cure&		operator=(Cure const &rhs);
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
