/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:12 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:36:13 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

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

# include <iostream>
# include <string>

class	AAnimal {
	protected:
		std::string		_type;

	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);

		AAnimal&		operator=(AAnimal const &rhs);
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif