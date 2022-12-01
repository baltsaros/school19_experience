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
		public:
			typedef Node<T>						node;

		private:
			node		*_root;

		public:
			RBTree<T>(): _root(NULL) {
				std::cout << "constructor" << std::endl;
			}

			virtual ~RBTree<T>() {deleteAll();}

			void	insert(T key) {
				if (!_root) {
					node	*child = new node(key, false, 0, NULL, NULL, NULL);

					_root = child;
					return ;
				}

				node	*child = new node(key, true, 0, NULL, NULL, NULL);
				node	*head = _root;
				node	*parent = NULL;
				while (head)
				{
					parent = head;
					if (head->key > child->key)
						head = head->left;
					else
						head = head->right;
					child->level++;
				}
				child->parent = parent;
				if (parent->key > child->key)
					parent->left = child;
				else
					parent->right = child;
				insertFixup(child);
			}

			void	insertFixup(node *child) {
				node	*uncle;

				if (child == _root || child->parent == _root)
					return ;
				while (child != _root && child->parent->color) {
					if (child->parent == child->parent->parent->left) {
						uncle = child->parent->parent->right;
						if (uncle && uncle->color) {
							child->parent->color = 0;
							uncle->color = 0;
							child->parent->parent->color = 1;
							child = child->parent->parent;
						}
						else {
							if (child == child->parent->right) {
								child = child->parent;
								leftRotation(child);
							}
							child->parent->color = 0;
							child->parent->parent->color = 1;
							rightRotation(child->parent->parent);
						} 
					}
					else {
						uncle = child->parent->parent->left;
						if (uncle && uncle->color) {
							child->parent->color = 0;
							uncle->color = 0;
							child->parent->parent->color = 1;
							child = child->parent->parent;
						}
						else {
							if (child == child->parent->left) {
								child = child->parent;
								rightRotation(child);
							}
							child->parent->color = 0;
							child->parent->parent->color = 1;
							leftRotation(child->parent->parent);
						}
					}
				}
				_root->color = 0;
			}

			void	rightRotation(node *x) {
				node	*y;

				std::cout << "right rotation\n";
				y = x->left;
				x->left = y->right;
				if (y->right)
					y->right->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->right = x;
				x->parent = y;
			}

			void	leftRotation(node *x) {
				node	*y;

				std::cout << "left rotation\n"; 
				y = x->right;
				x->right = y->left;
				if (y->left)
					y->left->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			node*	search(T key) {
				search(_root, key);
			}

			node*	search(node *tmp, T key) {
				if (!tmp || tmp->key == key)
					return (tmp);
				if (key > tmp->key)
					search(tmp->right, key);
				else
					search(tmp->left, key);
			}

			void	printNode() {
				int	level = 0;

				fixLevels(_root, level);
				printNode(_root);
			}

			void	fixLevels(node *tmp, int lvl) {
				tmp->level = lvl;
				++lvl;
				if (tmp->left)
					fixLevels(tmp->left, lvl);
				if (tmp->right)
					fixLevels(tmp->right, lvl);
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
			void	deleteOne(node *t) {

			}

			void	transplant(node *u, node *v) {
				if (!u->parent)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void	deleteFixup(node *z) {

			}

			void	deleteAll() {
				deleteAll(_root);
				_root = NULL;
			}

			void	deleteAll(node *tmp) {
				if (!tmp)
					return ;
				if (tmp->left)
					deleteAll(tmp->left);
				if (tmp->right)
					deleteAll(tmp->right);
				delete tmp;
			}


	};
}

#endif