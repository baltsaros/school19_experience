/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:11:29 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/12 10:20:25 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "Contact.hpp"


class	PhoneBook {
	private:
		Contact		_pb[8];
	public:
		void		fillContact(size_t i);
		void		displayList(void);
		Contact		getContact(size_t i);
};

#endif