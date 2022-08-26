/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:42:20 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:42:21 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	Zombie	*gouls;

	gouls = new Zombie[N];
	for (int i = 0; i < N; i++){
		gouls[i].setName(name);
	}
	return (gouls);
}
