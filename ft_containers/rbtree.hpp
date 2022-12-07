#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include "map.hpp"

// colors: 0/false - Black; 1/true - Red

namespace ft {

	template <class T>
	struct Node {
		T		key;
		bool	color;
		size_t	level;
		Node<T>	*left;
		Node<T>	*right;
		Node<T>	*parent;

		Node(Node *parent) : color(false), level(0),
			parent(parent), left(nullptr), right(nullptr) {} ;
		Node(T k, bool c, size_t lvl, Node *p, Node *l, Node *r) :
			key(k), color(c), level(lvl), parent(p), left(l), right(r) {} ;
	};

	template <class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<pair<const Key, T> > >
	class RBTree {
		public:
		// TYPEDEFS
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef pair<const Key, T>			value_type;
			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;
			typedef Compare						key_compare;
			typedef Allocator					allocator_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef Allocator::pointer			pointer;
			typedef Allocator::const_pointer	const_pointer;
			typedef Node<T>						node;
			typedef typename Allocator::template rebind<Node<T> >::other	alloc_node;
			// typedef iterator;
			// typedef const_iterator;
			// typedef reverse_iterator;
			// typedef const_reverse_iterator;

		private:
			node			*_root;
			node			*_nil;
			allocator_type	_alloc;
			alloc_node		_nalloc;
			size_type		_size;
			key_compare		_comp;

		public:
			RBTree<T>(key_compare const &comp, allocator_type const &alloc) :
				_alloc(alloc), _nalloc(alloc), _comp(comp), _size(0) {
				std::cout << "constructor" << std::endl;
				_root = nullptr;
				_nil = new node(_root);
			}

			RBTree<T>(RBTree const &src) :
				_alloc(src._alloc), _nalloc(src._alloc), _comp(src._comp), _size(0) {
				*this = src;
			}

			RBTree&	operator=(RBTree const &src) {
				if (this == &src)
					return (*this);
				if (_root)
					deleteAll();
				_root = nullptr;
				if (src._root) {
					copyTree(src._root, src._nil);
				}
				return (*this);
			}

			virtual ~RBTree<T>() {deleteAll();}

			void	copyTree(node *root, node *nil) {
				if (!_root) {
					node	*child = new node(root->key, root->color, root->level, _nil, _nil, _nil);

					_root = child;
				}
				else {
					node	*child = new node(root->key, root->color, root->level, nullptr, _nil, _nil);
					node	*head = _root;
					node	*parent = _nil;

					while (head != _nil)
					{
						parent = head;
						if (head->key > child->key)
							head = head->left;
						else
							head = head->right;
					}
					child->parent = parent;
					if (parent->key > child->key)
						parent->left = child;
					else
						parent->right = child;
				}
				if (root->left != nil)
					copyTree(root->left, nil);
				if (root->right != nil)
					copyTree(root->right, nil);
			}

			void	insert(T key) {
				if (!_root) {
					node	*child = new node(key, false, 0, _nil, _nil, _nil);

					_root = child;
					return ;
				}

				node	*child = new node(key, true, 0, nullptr, _nil, _nil);
				node	*head = _root;
				node	*parent = _nil;
				while (head != _nil)
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
						if (uncle != _nil && uncle->color) {
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
						if (uncle != _nil && uncle->color) {
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
				if (y->right != _nil)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == _nil)
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
				if (y->left != _nil)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == _nil)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			node*	search(T key) {
				node	*tmp;

				tmp = search(_root, key);
				return (tmp);
			}

			node*	search(node *tmp, T key) {
				if (tmp == _nil || tmp->key == key)
					return (tmp);
				if (key > tmp->key)
					return search(tmp->right, key);
				else
					return search(tmp->left, key);
			}

			void	transplant(node *u, node *v) {
				std::cout << "transplanting\n";
				if (u->parent == _nil)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void	deleteOne(T key) {
				node	*tmp = _root;

				std::cout << "deleting " << key << "\n";
				tmp = search(key);
				std::cout << "found: " << tmp->key << "\n";
				deleteOne(tmp);
			}

			void	deleteOne(node *toDelete)
			{
				node	*y, *x, *tmp;
				bool	y_color;

				y = toDelete;
				std::cout << "to delete: " << y->key << "\n";
				y_color = y->color;
				if (y->left == _nil) {
					x = y->right;
					transplant(y, y->right);
				}
				else if (y->right == _nil) {
					x = tmp->left;
					transplant(y, y->left);
				}
				else {
					tmp = y;
					y = findMin(tmp->right);
					y_color = y->color;
					x = y->right;
					if (y->parent != tmp) {
						transplant(y, y->right);
						y->right = tmp->right;
						tmp->right->parent = y;
					}
					transplant(tmp, y);
					y->left = tmp->left;
					y->left->parent = y;
					y->color = tmp->color;
				}
				std::cout << "to delete2: " << toDelete->key << "\n";
				delete toDelete;
				std::cout << "del fixup\n";
				if (!y_color)
					deleteFixup(x);
			}

			void	deleteFixup(node *x) {
				node	*w;

				while (x != _root && !x->color) {
					if (x == x->parent->left) {
						w = x->parent->right;
						if (w->color) {
							w->color = false;
							x->parent->color = true;
							leftRotation(x->parent);
							w = x->parent->right;
						}
						if (!w->left->color && !w->right->color) {
							w->color = true;
							x = x->parent;
						}
						else {
							if (!w->right->color) {
								w->left->color = false;
								w->color = true;
								rightRotation(w);
							}
							w->color = x->parent->color;
							x->parent->color = false;
							w->right->color = false;
							leftRotation(x->parent);
							x = _root;
						}
					}
					else {
						w = x->parent->left;
						if (w->color) {
							w->color = false;
							x->parent->color = true;
							rightRotation(x->parent);
							w = x->parent->left;
						}
						if (!w->right->color && !w->left->color) {
							w->color = true;
							x = x->parent;
						}
						else {
							if (!w->left->color) {
								w->right->color = false;
								w->color = true;
								leftRotation(w);
							}
							w->color = x->parent->color;
							x->parent->color = false;
							w->left->color = false;
							rightRotation(x->parent);
							x = _root;
						}
					}
				}
			}

			node*	findMin(node *tmp) {
				if (tmp == _nil)
					return (nullptr);
				while (tmp->left != _nil)
					tmp = tmp->left;
				return (tmp);
			}

			node*	findMax(node *tmp) {
				if (tmp == _nil)
					return (nullptr);
				while (tmp->right != _nil)
					tmp = tmp->right;
				return (tmp);
			}

			void	printNode() {
				int	level = 0;
				node	*tmp;

				if (!_root) {
					std::cout << "The tree does not exist!\n";
					return ;
				}
				fixLevels(_root, level);
				printNode(_root);
				tmp = findMin(_root);
				std::cout << "min: " << tmp->key << "\n";
				tmp = findMax(_root);
				std::cout << "max: " << tmp->key << "\n";
			}

			void	fixLevels(node *tmp, int lvl) {
				tmp->level = lvl;
				++lvl;
				if (tmp->left != _nil)
					fixLevels(tmp->left, lvl);
				if (tmp->right != _nil)
					fixLevels(tmp->right, lvl);
			}

			void	printNode(node *tmp) {
				std::cout.width(15); 
				std::cout << "root key: " << tmp->key << " | color: " << tmp->color;
				std::cout.width(10); 
				std::cout << " | level: " << tmp->level << "\n";
				if (tmp->left != _nil) {
					std::cout.width(15);
					std::cout << "left key: " << tmp->left->key << " | color: " << tmp->left->color;
					std::cout.width(10);
					std::cout << " | level: " << tmp->left->level << "\n";
				}
				if (tmp->right != _nil) {
					std::cout.width(15);
					std::cout << "right key: " << tmp->right->key << " | color: " << tmp->right->color;
					std::cout.width(10);
					std::cout << " | level: " << tmp->right->level << "\n";
				}
				if (tmp->left != _nil)
					printNode(tmp->left);
				if (tmp->right != _nil)
					printNode(tmp->right);
			}

			void	deleteAll() {
				deleteAll(_root);
				_root = nullptr;
				delete _nil;
				_nil = nullptr;
			}

			void	deleteAll(node *tmp) {
				if (tmp == _nil || !tmp)
					return ;
				if (tmp->left != _nil)
					deleteAll(tmp->left);
				if (tmp->right != _nil)
					deleteAll(tmp->right);
				delete tmp;
			}


	};
}

#endif