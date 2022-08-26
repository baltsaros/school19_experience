/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:41:57 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:48:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <new>

class	Zombie{
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie(void);
		void		announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif