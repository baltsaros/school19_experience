/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:43:14 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:43:15 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>


class Harl{
	
	typedef	struct s_funs{
		std::string	name;
		void		(Harl::*fun)(void);
	}	t_funs;

	private:
		t_funs	*_functions;
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};

#endif