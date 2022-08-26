/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:17 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:42:18 by abuzdin          ###   ########.fr       */
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
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		void		setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif