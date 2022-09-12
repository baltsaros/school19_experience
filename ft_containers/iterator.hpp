#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator: public iterator
		<typename iterator_traits<Iterator>::iterator_category,
		<typename iterator_traits<Iterator>::value_type,
		<typename iterator_traits<Iterator>::difference_type,
		<typename iterator_traits<Iterator>::pointer,
		<typename iterator_traits<Iterator>::reference> {


	protected:
		Iterator	_ptr;

	public:
		typedef Iterator											iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference type;
		typedef typename iterator_traits<Iterator>::reference		reference;
		typedef typename iterator_traits<Iterator>::pointer			pointer;
	};
}

#endif