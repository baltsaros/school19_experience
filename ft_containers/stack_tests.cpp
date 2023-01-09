#include <iostream>
#include <iterator>
#include <vector>
#include "vector.hpp"
#include <stack>
#include "stack.hpp"

int	main(void) {
	std::stack<int, std::vector<int> >	s1;
	ft::stack<int>						s2;

	// testing member functions
	std::cout << "+++ Testing std push and top +++" << std::endl;
	for (size_t i = 0; i < 7; ++i) {
		s1.push(i);
		std::cout << "push: " << i << std::endl;
		std::cout << "top: " << s1.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "+++ Testing ft push and top +++" << std::endl;
	for (size_t i = 0; i < 7; ++i) {
		s2.push(i);
		std::cout << "push: " << i << std::endl;
		std::cout << "top: " << s2.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "+++ Testing empty() +++" << std::endl;
	std::cout << "std s1 empty()? " << s1.empty() << std::endl;
	std::cout << "ft s2 empty()? " << s2.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "+++ Testing size() +++" << std::endl;
	std::cout << "std s1 size()? " << s1.size() << std::endl;
	std::cout << "ft s2 size()? " << s2.size() << std::endl;
	std::cout << std::endl;

	std::cout << "+++ Testing pop() +++" << std::endl;
	std::cout << "std s1 top(): " << s1.top() << std::endl;
	s1.pop();
	std::cout << "std s1 top() after pop(): " << s1.top() << std::endl;
	std::cout << "ft s2 top(): " << s2.top() << std::endl;
	s2.pop();
	std::cout << "ft s2 top() after pop(): " << s2.top() << std::endl;
	std::cout << std::endl;

	std::cout << "+++ copy constructor +++" << std::endl;
	std::stack<int, std::vector<int> >	s3(s1);
	ft::stack<int>						s4(s2);

	std::cout << "std s3(s1)" << std::endl;
	std::cout << "s3 top(): " << s3.top() << std::endl;
	std::cout << "s3 size(): " << s3.size() << std::endl;
	std::cout << "s3 empty(): " << s3.empty() << std::endl;
	std::cout << std::endl;
	std::cout << "ft s4(s2)" << std::endl;
	std::cout << "s4 top(): " << s4.top() << std::endl;
	std::cout << "s4 size(): " << s4.size() << std::endl;
	std::cout << "s4 empty(): " << s4.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "+++ operator= +++" << std::endl;
	std::stack<int, std::vector<int> >	s5;
	ft::stack<int>						s6;

	std::cout << "std s5 = s3" << std::endl;
	s5 = s3;
	std::cout << "s5 top(): " << s5.top() << std::endl;
	std::cout << "s5 size(): " << s5.size() << std::endl;
	std::cout << "s5 empty(): " << s5.empty() << std::endl;
	std::cout << "s5.push(7)" << std::endl;
	s5.push(7);
	std::cout << "s5.top(): " << s5.top() << std::endl;
	std::cout << std::endl;
	std::cout << "ft s6 = s4" << std::endl;
	s6 = s4;
	std::cout << "s6 top(): " << s6.top() << std::endl;
	std::cout << "s6 size(): " << s6.size() << std::endl;
	std::cout << "s6 empty(): " << s6.empty() << std::endl;
	std::cout << "s6.push(7)" << std::endl;
	s6.push(7);
	std::cout << "s6.top(): " << s6.top() << std::endl;
	std::cout << std::endl;

	std::cout << "+++ comparisons +++" << std::endl;
	std::cout << "s1 == s3 ? " << (s1 == s3) << std::endl;
	std::cout << "s1 != s3 ? " << (s1 != s3) << std::endl;
	std::cout << "s1 == s5 ? " << (s1 == s5) << std::endl;
	std::cout << "s1 >= s3 ? " << (s1 >= s3) << std::endl;
	std::cout << "s1 >  s3 ? " << (s1 > s3) << std::endl;
	std::cout << "s1 <= s3 ? " << (s1 <= s3) << std::endl;
	std::cout << "s1 <  s3 ? " << (s1 < s3) << std::endl;
	std::cout << "s1 <  s5 ? " << (s1 < s5) << std::endl;
	std::cout << "s5 >  s1 ? " << (s5 > s1) << std::endl;
	std::cout << std::endl;
	std::cout << "s2 == s4 ? " << (s2 == s4) << std::endl;
	std::cout << "s2 != s4 ? " << (s2 != s4) << std::endl;
	std::cout << "s2 == s6 ? " << (s2 == s6) << std::endl;
	std::cout << "s2 >= s4 ? " << (s2 >= s4) << std::endl;
	std::cout << "s2 >  s4 ? " << (s2 > s4) << std::endl;
	std::cout << "s2 <= s4 ? " << (s2 <= s4) << std::endl;
	std::cout << "s2 <  s4 ? " << (s2 < s4) << std::endl;
	std::cout << "s2 <  s6 ? " << (s2 < s6) << std::endl;
	std::cout << "s6 >  s2 ? " << (s6 > s2) << std::endl;
	std::cout << std::endl;

	std::cout << "+++ std vector with ft stack +++" << std::endl;
	ft::stack<int, std::vector<int> >	s10;
	for (size_t i = 0; i < 7; ++i) {
		s10.push(i);
		std::cout << "push: " << i << std::endl;
		std::cout << "top:  " << s10.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "s10 size(): " << s10.size() << std::endl;
	std::cout << "s10 empty(): " << s10.empty() << std::endl;
	s10.pop();
	std::cout << "s10 top() after pop(): " << s10.top() << std::endl;
	std::cout << std::endl;
	return (0);
}
