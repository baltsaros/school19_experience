#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include "map.hpp"

// colors: 0/false - Black; 1/true - Red

// namespace ft {

// 	struct Nil_Node {
// 		Nil_Node	*parent;
// 		Nil_Node	*left;
// 		Nil_Node	*right;
// 		bool		color;

// 		Nil_Node(): parent(NULL), left(NULL), right(NULL), color(0) {}

// 		Nil_Node(Nil_Node *parent, Nil_Node *child):
// 			parent(parent), left(child), right(child), color(1) {}

// 		Nil_Node(Nil_Node const &src):
// 			parent(src.parent), left(src.left), right(src.right), color(src.color) {}
// 	};

// 	template <class T>
// 	struct Node: Nil_Node {
// 		T	key;

// 		Node(): Nil_Node(), key(NULL) {}

// 		Node(T const &key, Nil_Node parent, Nil_Node child):
// 			Nil_Node(parent, child), key(key) {}

// 		Node(Nil_Node const &nil): Nil_Node(nil), key(NULL) {}

// 		Node(Node const &src): Nil_Node(src), key(src.key) {}
// 	};

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

// }

namespace ft {

	template <class T>
	struct Node {
		T		key;
		bool	color;
		size_t	level;
		Node<T>	*left;
		Node<T>	*right;
		Node<T>	*parent;
		Node(T k, bool c, size_t lvl, Node *p, Node *l, Node *r) :
			key(k), color(c), level(lvl), parent(p), left(l), right(r) {} ;
	};

	template <class T>
	class RBTree {
		// public:
			typedef Node<T>						node;

		private:
			node		*_root;

		public:
			RBTree<T>(): _root(NULL) {
				std::cout << "constructor" << std::endl;
			}

			virtual ~RBTree<T>() {deleteNodes();}

			void	insert(T key) {
				if (!_root) {
					node	*n = new node(key, false, 0, NULL, NULL, NULL);

					_root = n;
					return ;
				}

				node	*n = new node(key, true, 0, NULL, NULL, NULL);
				node	*head = _root;
				node	*parent = NULL;
				while (head)
				{
					parent = head;
					if (head->key > n->key)
						head = head->left;
					else
						head = head->right;
					n->level++;
				}
				n->parent = parent;
				if (parent->key > n->key)
					parent->left = n;
				else
					parent->right = n;
				checkTree();
			}

			void	checkTree() {
				checkTree(_root, NULL);
			}

			void	checkTree(node *parent, node *uncle) {
				if (parent->left && parent->color && parent->left->color) {
					if (uncle && uncle->color)
						swapColors(parent, uncle);
					else if (parent != _root)
						rightRotation(parent, parent->left);
				}
				if (parent->right && parent->color && parent->right->color) {
					if (uncle && uncle->color)
						swapColors(parent, uncle);
					else if (parent != _root)
						leftRotation(parent, parent->right);
				}
				if (parent->left)
					checkTree(parent->left, parent->right);
				if (parent->right)
					checkTree(parent->right, parent->left);
			}

			void	swapColors(node *parent, node *uncle) {
				parent->color = !(parent->color);
				if (parent->parent && parent->parent != _root)
					parent->parent->color = !(parent->parent->color);
				if (uncle)
					uncle->color = !(uncle->color);
			}

			void	rightRotation(node *parent, node *child) {
				std::cout << "right rotation\n";
			}

			void	leftRotation(node *parent, node *child) {
				std::cout << "left rotation\n";

			}

			void	printNode() {
				printNode(_root);
			}

			void	printNode(node *tmp) {
				std::cout << "root key: " << tmp->key << " | color: " << tmp->color;
				std::cout << " | level: " << tmp->level << "\n";
				if (tmp->left) {
					std::cout << "left key: " << tmp->left->key << " | color: " << tmp->left->color;
					std::cout << " | level: " << tmp->left->level << "\n";
				}
				if (tmp->right) {
					std::cout << "right key: " << tmp->right->key << " | color: " << tmp->right->color;
					std::cout << " | level: " << tmp->right->level << "\n";
				}
				if (tmp->left)
					printNode(tmp->left);
				if (tmp->right)
					printNode(tmp->right);
			}

			void	deleteNodes() {
				deleteNodes(_root);
				_root = NULL;
			}

			void	deleteNodes(node *tmp) {
				if (tmp->left)
					deleteNodes(tmp->left);
				if (tmp->right)
					deleteNodes(tmp->right);
				delete tmp;
			}

			// void	leftRotate()

	};
}

#endif