#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include "map.hpp"

// colors: 0/false - Black; 1/true - Red

namespace ft {

	struct Nil_Node {
		Nil_Node	*parent;
		Nil_Node	*left;
		Nil_Node	*right;
		bool		color;

		Nil_Node(): parent(NULL), left(NULL), right(NULL), color(0) {}

		Nil_Node(Nil_Node *parent, Nil_Node *child):
			parent(parent), left(child), right(child), color(1) {}

		Nil_Node(Nil_Node const &src):
			parent(src.parent), left(src.left), right(src.right), color(src.color) {}
	};

	template <class T>
	struct Node: Nil_Node {
		T	key;

		Node(): Nil_Node(), key(NULL) {}

		Node(T const &key, Nil_Node parent, Nil_Node child):
			Nil_Node(parent, child), key(key) {}

		Node(Nil_Node const &nil): Nil_Node(nil), key(NULL) {}

		Node(Node const &src): Nil_Node(src), key(src.key) {}
	};

	// template <class Key,
	// 			class T,
	// 			// class Compare,
	// 			// class Allocator>
	// 			class Compare = std::less<Key>,
	// 			class Allocator = std::allocator<pair<const Key, T> > >
	// class RBTree {
	// 	public:
	// 	// TYPEDEFS
	// 		// typedef Key							key_type;
	// 		typedef T							mapped_type;
	// 		// typedef pair<const Key, T>			value_type;
	// 		typedef std::size_t					size_type;
	// 		typedef std::ptrdiff_t				difference_type;
	// 		typedef Compare						key_compare;
	// 		typedef Allocator					allocator_type;
	// 		typedef value_type&					reference;
	// 		typedef const value_type&			const_reference;
	// 		typedef Allocator::pointer			pointer;
	// 		typedef Allocator::const_pointer	const_pointer;
	// 		typedef Nil_Node					nnode;
	// 		typedef Node<T>						node;
	// 		typedef typename Allocator::template rebind<Nil_Node>::other	alloc_nil;
	// 		typedef typename Allocator::template rebind<Node<T> >::other		alloc_node;
	// 		// typedef iterator;
	// 		// typedef const_iterator;
	// 		// typedef reverse_iterator;
	// 		// typedef const_reverse_iterator;

	// 	private:
	// 		nnode			*_root;
	// 		nnode			*_nil;
	// 		allocator_type	_alloc;
	// 		alloc_nil		_nn_alloc;
	// 		alloc_nil		_node_alloc;
	// 		size_type		_size;
	// 		key_compare		_comp;

	// 	public:
	// 		RBTree(Compare const &comp, Allocator const &alloc):
	// 			_alloc(alloc), _nn_alloc(alloc), _node_alloc(alloc),
	// 			_size(0), _comp(comp) {

	// 				_nil = _nilInit();
	// 				_root = _nil;
	// 			}

	// 	nnode	*_nilInit() {
	// 		nnode	*nil = _nn_alloc.allocate(1);
	// 		_nn_alloc.construct(nil, &nil);
	// 		return (nil);
	// 	}

	// };

	template <class T, class Allocator = std::allocator<T> >
	class RBTree {
		public:
			typedef Nil_Node					nnode;
			typedef Node<T>						node;
			typedef std::size_t					size_type;
			// typedef typename Allocator::template rebind<Nil_Node>::other	alloc_nil;
			// typedef typename Allocator::template rebind<Node<T> >::other		alloc_node;

		private:
			nnode		*_root;
			nnode		*_nil;
			Allocator	_alloc;
			// alloc_nil	_nn_alloc;
			// alloc_nil	_node_alloc;
			size_type	_size;

		public:
			RBTree(): _root(NULL), _nil(NULL), _alloc(), _size(0) {
				std::cout << "constr 1" << std::endl;
			}

			RBTree(const Allocator &alloc): _size(0), _alloc(alloc) {
				std::cout << "constr 2" << std::endl;
				_nil = nilInit();
				_root = _nil;
			}

			~RBTree(){}

			nnode	*nilInit() {
				nnode	*nil = _alloc.allocate(1);
				_alloc.construct(nil, &nil);
				return (nil);
			}
	};
}

#endif