#include <iostream>
#include <iterator>
#include <vector>
#include <exception>
#include "vector.hpp"

// using namespace std;

int	main(void) {

	// testing size vs capacity
	{
		// std::vector<int>	v1 (100, 100);

		// std::cout << "size: " << v1.size() << std::endl;
		// std::cout << "capacity: " << v1.capacity() << std::endl;
	}
	// testing out_of_range
	{
		// std::vector<int>	v1 (4, 100);

		// std::cout << "v1[0]: " << v1[0] << std::endl;
		// std::cout << "v1[3]: " << v1[3] << std::endl;
		// cout << "v1[4]: " << v1.at(4) << endl;
		// if (1 < 2)
		// 	throw out_of_range("range error");
	}

	// ft_vector: assign, allocator
	// {
	// 	std::vector<int>	v1 (4, 100);
	// 	ft::vector<int>		v2(4, 100);
	// 	int					*p;
	
	// 	v1.assign(2, 5);
	// 	std::cout << "get_allocator: getting type for int array, allocate memory for it and fill it" << std::endl;
	// 	p = v1.get_allocator().allocate(3);
	// 	for (size_t i = 0; i < 3; ++i) {
	// 		v1.get_allocator().construct(&p[i], i);
	// 		std::cout << "std: " << p[i] << std::endl;
	// 		v1.get_allocator().destroy(&p[i]);
	// 	}
	// 	v1.get_allocator().deallocate(p, 3);
	// 	p = v2.get_allocator().allocate(3);
	// 	for (size_t i = 0; i < 3; ++i) {
	// 		v2.get_allocator().construct(&p[i], i);
	// 		std::cout << "ft: " << p[i] << std::endl;
	// 		v2.get_allocator().destroy(&p[i]);
	// 	}
	// 	v1.get_allocator().deallocate(p, 3);
	// }

	// ft_vector: access operators
	// {
	// 	std::vector<int>	v1(4, 100);
	// 	ft::vector<int>		v2(4, 100);
	// 	ft::vector<int>		v4;
	// 	int					*p;

	// 	std::cout << "v1.at(0): " << v1.at(0) << std::endl;
	// 	std::cout << "v2.at(0): " << v2.at(0) << std::endl;
	// 	std::cout << "v1.at(3): " << v1.at(3) << std::endl;
	// 	std::cout << "v2.at(3): " << v2.at(3) << std::endl;
	// 	std::cout << "v1.at(2) = 3: " << (v1.at(2) = 3) << std::endl;
	// 	std::cout << "v1.at(2): " << v1.at(2) << std::endl;
	// 	std::cout << "v2.at(2) = 3: " << (v2.at(2) = 3) << std::endl;
	// 	std::cout << "v2.at(2): " << v2.at(2) << std::endl;
	// 	// std::cout << "v1.at(4): " << v1.at(4) << std::endl;
	// 	// std::cout << "v2.at(4): " << v2.at(4) << std::endl;

	// 	std::cout << "v1[0]: " << v1[0] << std::endl;
	// 	std::cout << "v2[0]: " << v2[0] << std::endl;
	// 	std::cout << "v1[2]: " << v1[2] << std::endl;
	// 	std::cout << "v2[2]: " << v2[2] << std::endl;
	// 	// std::cout << "v1[5]: " << v1[5] << std::endl;
	// 	// std::cout << "v2[5]: " << v2[5] << std::endl;

	// 	std::cout << "v1.front(): " << v1.front() << std::endl;
	// 	std::cout << "v2.front(): " << v2.front() << std::endl;
	// 	// std::cout << "EMPTY: v4.front(): " << v4.front() << std::endl;

	// 	std::cout << "v1.at(3) = 6: " << (v1.at(3) = 6) << std::endl;
	// 	std::cout << "v1.at(3): " << v1.at(3) << std::endl;
	// 	std::cout << "v2.at(3) = 6: " << (v2.at(3) = 6) << std::endl;
	// 	std::cout << "v2.at(3): " << v2.at(3) << std::endl;
	// 	std::cout << "v1.back(): " << v1.back() << std::endl;
	// 	std::cout << "v2.back(): " << v2.back() << std::endl;

	// 	std::cout << "p = v1.data(): " << (p = v1.data()) << std::endl;
	// 	std::cout << "p[3]: " << p[3] << std::endl;
	// 	std::cout << "p = v2.data(): " << (p = v2.data()) << std::endl;
	// 	std::cout << "p[3]: " << p[3] << std::endl;
	// }

	// ft_vector: capacity
	// {
	// 	std::vector<int>	v1(4, 100);
	// 	ft::vector<int>		v2(4, 100);
	// 	std::vector<int>	v3;
	// 	ft::vector<int>		v4;

	// 	std::cout << "std: v1 empty? " << v1.empty() << std::endl;
	// 	std::cout << "ft: v2 empty? " << v2.empty() << std::endl;
	// 	std::cout << "std: v3 empty? " << v3.empty() << std::endl;
	// 	std::cout << "ft: v4 empty? " << v4.empty() << std::endl;

	// 	std::cout << "std: v1.size(): " << v1.size() << std::endl;
	// 	std::cout << "ft: v2.size(): " << v2.size() << std::endl;
	// 	std::cout << "std: v3.size(): " << v3.size() << std::endl;
	// 	std::cout << "ft: v4.size(): " << v4.size() << std::endl;

	// 	std::cout << "std: v1.max_size(): " << v1.max_size() << std::endl;
	// 	std::cout << "ft: v2.max_size(): " << v2.max_size() << std::endl;
	// 	std::cout << "std: v3.max_size(): " << v3.max_size() << std::endl;
	// 	std::cout << "ft: v4.max_size(): " << v4.max_size() << std::endl;

	// 	std::cout << "std: v1.reserve(150): " << std::endl;
	// 	v1.reserve(150);
	// 	std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
	// 	std::cout << "v1[0]: " << v1[0] << std::endl;
	// 	std::cout << "v1[2]: " << v1[2] << std::endl;
	// 	std::cout << "ft: v2.reserve(150): " << std::endl;
	// 	v2.reserve(150);
	// 	std::cout << "v2.capacity(): " << v2.capacity() << std::endl;
	// 	std::cout << "v2[0]: " << v2[0] << std::endl;
	// 	std::cout << "v2[2]: " << v2[2] << std::endl;
	// 	// std::cout << "reserve(4611686018427387904): " << std::endl;
	// 	// v3.reserve(4611686018427387904);
	// 	// v4.reserve(4611686018427387904);
	// 	std::cout << "reserve(10) empty containers: " << std::endl;
	// 	v3.reserve(10);
	// 	std::cout << "v3.capacity(): " << v3.capacity() << std::endl;
	// 	v4.reserve(10);
	// 	std::cout << "v4.capacity(): " << v4.capacity() << std::endl;
	// }

	// ft_vector: modifiers
	// {
	// 	std::vector<int>	v1(4, 100);
	// 	ft::vector<int>		v2(4, 100);
	// 	std::vector<int>	v3;
	// 	ft::vector<int>		v4;

		// std::cout << "std: v1.clear()" << std::endl;
		// std::cout << "v1.size: " << v1.size() << std::endl;
		// std::cout << "v1.capacity: " << v1.capacity() << std::endl;
		// std::cout << "clearing" << std::endl;
		// v1.clear();
		// std::cout << "v1.size: " << v1.size() << std::endl;
		// std::cout << "v1.capacity: " << v1.capacity() << std::endl;
		// std::cout << "ft: v2.clear()" << std::endl;
		// std::cout << "v2.size: " << v2.size() << std::endl;
		// std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		// std::cout << "clearing" << std::endl;
		// v2.clear();
		// std::cout << "v2.size: " << v2.size() << std::endl;
		// std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		
	// 	std::cout << "std: v1.push_back()" << std::endl;
	// 	std::cout << "v1.back(): " << v1.back() << std::endl;
	// 	std::cout << "v1.size: " << v1.size() << std::endl;
	// 	std::cout << "v1.capacity: " << v1.capacity() << std::endl;
	// 	std::cout << "pushing 3 to the end..." << std::endl;
	// 	v1.push_back(3);
	// 	std::cout << "v1.back(): " << v1.back() << std::endl;
	// 	std::cout << "v1.size: " << v1.size() << std::endl;
	// 	std::cout << "v1.capacity: " << v1.capacity() << std::endl;
	// 	std::cout << "ft: v2.push_back()" << std::endl;
	// 	std::cout << "v2.back(): " << v2.back() << std::endl;
	// 	std::cout << "v2.size: " << v2.size() << std::endl;
	// 	std::cout << "v2.capacity: " << v2.capacity() << std::endl;
	// 	std::cout << "pushing 3 to the end..." << std::endl;
	// 	v2.push_back(3);
	// 	std::cout << "v2.back(): " << v2.back() << std::endl;
	// 	std::cout << "v2.size: " << v2.size() << std::endl;
	// 	std::cout << "v2.capacity: " << v2.capacity() << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << "std: v1.pop_back()" << std::endl;
	// 	std::cout << "v1.back(): " << v1.back() << std::endl;
	// 	std::cout << "v1.size: " << v1.size() << std::endl;
	// 	std::cout << "v1.capacity: " << v1.capacity() << std::endl;
	// 	std::cout << "popping..." << std::endl;
	// 	v1.pop_back();
	// 	std::cout << "v1.back(): " << v1.back() << std::endl;
	// 	std::cout << "v1.size: " << v1.size() << std::endl;
	// 	std::cout << "v1.capacity: " << v1.capacity() << std::endl;
	// 	std::cout << "ft: v2.push_back()" << std::endl;
	// 	std::cout << "v2.back(): " << v2.back() << std::endl;
	// 	std::cout << "v2.size: " << v2.size() << std::endl;
	// 	std::cout << "v2.capacity: " << v2.capacity() << std::endl;
	// 	std::cout << "popping..." << std::endl;
	// 	v2.pop_back();
	// 	std::cout << "v2.back(): " << v2.back() << std::endl;
	// 	std::cout << "v2.size: " << v2.size() << std::endl;
	// 	std::cout << "v2.capacity: " << v2.capacity() << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << "popping empty vectors" << std::endl;
	// 	std::cout << "std:\n";
	// 	v3.pop_back();
	// 	std::cout << "ft:\n";
	// 	v4.pop_back();
	// }

	// iterators
	{
		std::vector<int>	v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		std::vector<int>::iterator	it1;
		std::vector<int>::iterator	it3;
		std::vector<int>::iterator	it5;
		ft::vector<int>		v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		ft::vector<int>::iterator	it2;
		ft::vector<int>::iterator	it4;
		ft::vector<int>::iterator	it6;


		std::cout << "v1.size: " << v1.size() << std::endl;
		std::cout << "v1.capacity: " << v1.capacity() << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << "std: v1.begin()" << std::endl;
		std::cout << *(v1.begin()) << std::endl;
		it1 = v1.begin();
		std::cout << "it1: " << *it1 << std::endl;
		std::cout << "ft: v2.begin()" << std::endl;
		std::cout << *(v2.begin()) << std::endl;
		it2 = v2.begin();
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << std::endl;

		std::cout << "std: v1.end()" << std::endl;
		std::cout << *(v1.end()) << std::endl;
		std::cout << "ft: v2.end()" << std::endl;
		std::cout << *(v2.end()) << std::endl;
		std::cout << std::endl;
		
		std::cout << "pre-in/decrementation" << std::endl;
		it3 = v1.end();
		it4 = v2.end();
		std::cout << "(std)it3: " << *it3 << std::endl;
		std::cout << "(ft)it4: " << *it4 << std::endl;
		--it3;
		--it4;
		std::cout << "--it3: " << *it3 << std::endl;
		std::cout << "--it4: " << *it4 << std::endl;
		--it3;
		--it4;
		std::cout << "--it3: " << *it3 << std::endl;
		std::cout << "--it4: " << *it4 << std::endl;
		std::cout << "it3--: " << *(it3--) << std::endl;
		std::cout << "it4--: " << *(it4--) << std::endl;
		std::cout << "it3: " << *it3 << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it3--: " << *(it3--) << std::endl;
		std::cout << "it4--: " << *(it4--) << std::endl;
		std::cout << "it3: " << *it3 << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		++it3;
		++it4;
		std::cout << "++it3: " << *it3 << std::endl;
		std::cout << "++it4: " << *it4 << std::endl;
		++it3;
		++it4;
		std::cout << "++it3: " << *it3 << std::endl;
		std::cout << "++it4: " << *it4 << std::endl;
		std::cout << "it3++: " << *(it3++) << std::endl;
		std::cout << "it4++: " << *(it4++) << std::endl;
		std::cout << "it3: " << *it3 << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it3++: " << *(it3++) << std::endl;
		std::cout << "it4++: " << *(it4++) << std::endl;
		std::cout << "it3: " << *it3 << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << std::endl;

		std::cout << "arithmetic operations" << std::endl;
		std::cout << "(std)it3: " << *it3 << std::endl;
		std::cout << "(ft)it4: " << *it4 << std::endl;
		it3 -= 2;
		it4 -= 2;
		std::cout << "it3 -= 2: " << *it3 << std::endl;
		std::cout << "it4 -= 2: " << *it4 << std::endl;
		it3 -= 1;
		it4 -= 1;
		std::cout << "it3 -= 1: " << *it3 << std::endl;
		std::cout << "it4 -= 1: " << *it4 << std::endl;
		it3 += 2;
		it4 += 2;
		std::cout << "it3 += 2: " << *it3 << std::endl;
		std::cout << "it4 += 2: " << *it4 << std::endl;
		std::cout << "it3 - 2: " << *it3 << " - " << 2 << " = ";
		std::cout << *(it3 - 2) << std::endl;
		std::cout << "it4 - 2: " << *it4 << " - " << 2 << " = ";
		std::cout << *(it4 - 2) << std::endl;
		std::cout << "(std)it3: " << *it3 << std::endl;
		std::cout << "(ft)it4: " << *it4 << std::endl;
		std::cout << "it3 + 1: " << *it3 << " + " << 1 << " = ";
		std::cout << *(it3 + 1) << std::endl;
		std::cout << "it4 + 1: " << *it4 << " + " << 1 << " = ";
		std::cout << *(it4 + 1) << std::endl;
		std::cout << std::endl;

		std::cout << "operator[]" << std::endl;
		it3 = v1.begin();
		it4 = v2.begin();
		std::cout << "(std)it3[0]: " << it3[0] << std::endl;
		std::cout << "(ft)it4[0]: " << it4[0] << std::endl;
		std::cout << "(std)it3[1]: " << it3[1] << std::endl;
		std::cout << "(ft)it4[1]: " << it4[1] << std::endl;
		std::cout << "(std)it3[2]: " << it3[2] << std::endl;
		std::cout << "(ft)it4[2]: " << it4[2] << std::endl;
		std::cout << "(std)it3[3]: " << it3[3] << std::endl;
		std::cout << "(ft)it4[3]: " << it4[3] << std::endl;
		std::cout << "(std)it3: " << *it3 << std::endl;
		std::cout << "(ft)it4: " << *it4 << std::endl;

		std::cout << "comparisons" << std::endl;
		it3 = it3 + 2;
		it4 = it4 + 2;
		std::cout << "(std)it1: " << *it1 << std::endl;
		std::cout << "(std)it3: " << *it3 << std::endl;
		std::cout << "(ft)it2: " << *it2 << std::endl;
		std::cout << "(ft)it4: " << *it4 << std::endl;
		std::cout << "std: " << *it1 << " < " << *it3 << " ? ";
		std::cout << (it1 < it3) << std::endl;
		std::cout << "ft: " << *it2 << " < " << *it4 << " ? ";
		std::cout << (it2 < it4) << std::endl;
		std::cout << "std: " << *it1 << " > " << *it3 << " ? ";
		std::cout << (it1 > it3) << std::endl;
		std::cout << "ft: " << *it2 << " > " << *it4 << " ? ";
		std::cout << (it2 > it4) << std::endl;
		std::cout << "std: " << *it1 << " <= " << *it3 << " ? ";
		std::cout << (it1 <= it3) << std::endl;
		std::cout << "ft: " << *it2 << " <= " << *it4 << " ? ";
		std::cout << (it2 <= it4) << std::endl;
		std::cout << "std: " << *it1 << " >= " << *it3 << " ? ";
		std::cout << (it1 >= it3) << std::endl;
		std::cout << "ft: " << *it2 << " >= " << *it4 << " ? ";
		std::cout << (it2 >= it4) << std::endl;
		std::cout << "std: " << *it1 << " == " << *it3 << " ? ";
		std::cout << (it1 == it3) << std::endl;
		std::cout << "ft: " << *it2 << " == " << *it4 << " ? ";
		std::cout << (it2 == it4) << std::endl;
		std::cout << "std: " << *it1 << " != " << *it3 << " ? ";
		std::cout << (it1 != it3) << std::endl;
		std::cout << "ft: " << *it2 << " != " << *it4 << " ? ";
		std::cout << (it2 != it4) << std::endl;
	}
	return (0);
}