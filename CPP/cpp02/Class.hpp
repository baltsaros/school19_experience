#ifndef
# define

#include <iostream>
#include <string>

class	Class {
	private:

	public:
		Class(void);
		Class(Class const &src);
		~Class(void);
		Class&	operator=(Class const &rhs);
};

#endif