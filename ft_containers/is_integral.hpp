#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {
	template <class T, T v>
	struct integral_constant {
		static const T						value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		const operator T() {return v;}
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	
}
#endif