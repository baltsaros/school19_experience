/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_set.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:30 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 15:08:35 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_SET_HPP
# define RBTREE_SET_HPP

# include "rbtree_iterator.hpp"
# include "../containers/set.hpp"

# define BLACK	false
# define RED	true

// colors: 0/false - Black; 1/true - Red

namespace ft {
	template <class Value>
	struct Node {
		typedef	const Node	const_Node;

		Value		value;
		bool		color;
		size_t		level;
		Node<Value>	*left;
		Node<Value>	*right;
		Node<Value>	*parent;

		Node(Node *parent) : color(BLACK), level(0),
			left(NULL), right(NULL), parent(parent) {}

		Node(Value v, bool c, size_t lvl, Node *l, Node *r, Node *p) :
			value(v), color(c), level(lvl), left(l), right(r), parent(p) {}

	};

	template <class Key,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<Key> >
	class RBTree {
		public:
		// TYPEDEFS
			typedef Key						key_type;
			typedef Key						value_type;
			typedef std::size_t				size_type;
			typedef std::ptrdiff_t			difference_type;
			typedef Compare					key_compare;
			typedef Allocator				allocator_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<Key>				node;

			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::template rebind<Node<key_type> >::other	alloc_node;
			
			typedef rbt_iterator<Key>						iterator;
			typedef rbt_const_iterator<Key>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			node			*_root;
			node			*_nil;
			allocator_type	_alloc;
			alloc_node		_node_alloc;
			size_type		_size;
			key_compare		_comp;

		public:
			explicit RBTree(key_compare const &comp = key_compare(),
				allocator_type const &alloc = allocator_type()) :
				_alloc(alloc), _node_alloc(alloc), _size(0), _comp(comp) {
				_root = NULL;
				_nil = _node_alloc.allocate(1);
				_node_alloc.construct(_nil, node(_root));
				_root = _nil;
			}

			RBTree(RBTree const &src) :
				_alloc(src._alloc), _node_alloc(src._alloc), _size(0), _comp(src._comp) {
				*this = src;
			}

			RBTree&	operator=(RBTree const &src) {
				if (this == &src)
					return (*this);
				_alloc = src._alloc;
				_node_alloc = src._node_alloc;
				_comp = src._comp;
				if (_root)
					clear();
				_root = NULL;
				if (src._root && src._root != src._nil)
					insert(src.begin(), src.end());
				else if (src._root == src._nil)
					_root = _nil;
				return (*this);
			}

			virtual ~RBTree() {
				// std::cout << "destructor\n";
				clear();
				if (!_nil)
					return ;
				_node_alloc.destroy(_nil);
				_node_alloc.deallocate(_nil, 1);
				_nil = NULL;
			}

			// ELEMENT ACCESS
			Key&	at(const value_type& key) {
				node	*tmp = NULL;

				tmp = search(key);
				if (!tmp || (!tmp->left && !tmp->right))
					throw OutOfRange();
				return (tmp->value);
			}

			const Key&	at(const value_type& key) const {
				node	*tmp = NULL;

				tmp = search(key);
				if (!tmp || (!tmp->left && !tmp->right))
					throw OutOfRange();
				return (tmp->value);
			}

			Key&	operator[](const Key& key) {
				node			*tmp = NULL;

				tmp = search(key);
				if (!tmp || (!tmp->left && !tmp->right)) {
					insert(key);
					tmp = search(key);
				}
				return (tmp->value);
			}

			// ITERATORS
			iterator	begin() {
				return (iterator(findMin(_root)));
			}

			const_iterator	begin() const {
				return (const_iterator(findMin(_root)));
			}

			iterator	end() {
				return (iterator(_nil));
			}

			const_iterator	end() const {
				return (const_iterator(_nil));
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(end()));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(begin()));
			}

			// CAPACITY
			bool	empty() const {
				return (!_size);
			}

			size_type	size() const {
				return (_size);
			}

			size_type	max_size() const {
				return (_node_alloc.max_size());
			}

			pair<iterator, bool>	create_root(const value_type& value) {
					node					*child;
					pair<iterator, bool>	ret;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(value, BLACK, 0, _nil, _nil, _nil));
					_root = child;
					_nil->parent = _root;
					_size++;
					ret = ft::make_pair(iterator(child), true);
					return (ret);
			}

			// MODIFIERS
			pair<iterator, bool>	insert(const value_type& value) {
				if (!_root || _root == _nil)
					return (create_root(value));

				node					*child;
				node					*head = _root;
				node					*parent = _nil;
				node					*tmp;
				pair<iterator, bool>	ret;

				tmp = search(value);
				if (tmp != _nil) {
					ret = ft::make_pair(iterator(tmp), false);
					return (ret);
				}
				child = _node_alloc.allocate(1);
				_node_alloc.construct(child, node(value, RED, 0, _nil, _nil, NULL));

				while (head != _nil)
				{
					parent = head;
					if (_comp(child->value, head->value))
						head = head->left;
					else
						head = head->right;
					child->level++;
				}
				child->parent = parent;
				if (_comp(child->value, parent->value))
					parent->left = child;
				else
					parent->right = child;
				_size++;
				insertFixup(child);
				ret = ft::make_pair(iterator(child), true);
				return (ret);
			}

			iterator	insert(iterator pos, const value_type& value) {
				(void)pos;
				if (!_root || _root == _nil)
					return (create_root(value).first);

				node	*child;
				node	*head = _root;
				node	*parent = _nil;
				node	*tmp;

				tmp = search(value);
				if (tmp != _nil)
					return (iterator(tmp));
				child = _node_alloc.allocate(1);
				_node_alloc.construct(child, node(value, RED, 0, _nil, _nil, NULL));

				while (head != _nil)
				{
					parent = head;
					if (_comp(child->value, head->value))
						head = head->left;
					else
						head = head->right;
					child->level++;
				}
				child->parent = parent;
				if (_comp(child->value, parent->value))
					parent->left = child;
				else
					parent->right = child;
				_size++;
				insertFixup(child);
				return (iterator(child));
			}

			iterator	insert(const_iterator pos, const value_type& value) {
				(void)pos;
				if (!_root || _root == _nil)
					return (create_root(value).first);

				node	*child;
				node	*head = _root;
				node	*parent = _nil;
				node	*tmp;

				tmp = search(value);
				if (tmp != _nil)
					return (iterator(tmp));
				child = _node_alloc.allocate(1);
				_node_alloc.construct(child, node(value, RED, 0, _nil, _nil, NULL));

				while (head != _nil)
				{
					parent = head;
					if (_comp(child->value, head->value))
						head = head->left;
					else
						head = head->right;
					child->level++;
				}
				child->parent = parent;
				if (_comp(child->value, parent->value))
					parent->left = child;
				else
					parent->right = child;
				_size++;
				insertFixup(child);
				return (iterator(child));
			}

			template <class InputIt>
			void	insert(InputIt first, InputIt last) {
				for (; first != last; ++first)
					insert(*first);
			}

			void	erase(iterator pos) {
				node	*tmp = pos.base();

				if (!tmp || tmp == _nil)
					return ;
				deleteOne(tmp);
			}

			void	erase(const_iterator pos) {
				node	*tmp = pos.base();

				if (!tmp || tmp == _nil)
					return ;
				deleteOne(tmp);
			}

			void	erase(iterator first, iterator last) {
				while (first != last)
					erase(first++);
			}

			void	erase(const_iterator first, const_iterator last) {
				while (first != last)
					erase(first++);
			}
			
			bool	erase(const value_type& key) {
				node	*tmp;

				tmp = search(key);
				if (!tmp || tmp == _nil)
					return (false);
				deleteOne(tmp);
				return (true);
			}

			void	clear() {
				if (_root == _nil || !_root)
					return ;
				deleteAll(_root);
				_root = _nil;
				_root->parent = _nil;
			}

			void	swap(RBTree& other) {
				RBTree	tmp;

				tmp._node_alloc.destroy(tmp._nil);
				tmp._node_alloc.deallocate(tmp._nil, 1);
				tmp._nil = NULL;

				tmp._size = _size;
				tmp._nil = _nil;
				tmp._root = _root;
				tmp._alloc = _alloc;
				tmp._node_alloc = _node_alloc;
				tmp._comp = _comp;

				_size = other._size;
				_nil = other._nil;
				_root = other._root;
				_alloc = other._alloc;
				_node_alloc = other._node_alloc;
				_comp = other._comp;

				other._size = tmp._size;
				other._nil = tmp._nil;
				other._root = tmp._root;
				other._alloc = tmp._alloc;
				other._node_alloc = tmp._node_alloc;
				other._comp = tmp._comp;

				tmp._root = NULL;
				tmp._nil = NULL;
			}

			// LOOKUPS
			size_type	count(const value_type& key) const {
				node	*tmp = search(key);

				if (!tmp || tmp == _nil)
					return (false);
				return (true);
			}

			iterator	find(const value_type& key) {
				node	*tmp = search(key);

				return (iterator(tmp));
			}

			const_iterator	find(const value_type& key) const {
				node	*tmp = search(key);

				return (const_iterator(tmp));
			}

			pair<iterator, iterator>	equal_range(const value_type& key) {
				pair<iterator, iterator>	ret;

				ret = ft::make_pair(lower_bound(key), upper_bound(key));
				return (ret);
			}

			pair<const_iterator, const_iterator>	equal_range(const value_type& key) const {
				pair<const_iterator, const_iterator>	ret;

				ret = ft::make_pair(lower_bound(key), upper_bound(key));
				return (ret);
			}

			iterator	lower_bound(const value_type& key) {
				node	*tmp = _root;
				node	*ret = _nil;

				while (tmp != _nil) {
					if (!_comp(tmp->value, key)) {
						ret = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return (iterator(ret));
			}

			const_iterator	lower_bound(const value_type& key) const {
				node	*tmp = _root;
				node	*ret = _nil;

				while (tmp != _nil) {
					if (!_comp(tmp->value, key)) {
						ret = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return (const_iterator(ret));
			}

			iterator	upper_bound(const value_type& key) {
				node	*tmp = _root;
				node	*ret = _nil;

				while (tmp != _nil) {
					if (_comp(key, tmp->value)) {
						ret = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return (iterator(ret));
			}

			const_iterator	upper_bound(const value_type& key) const {
				node	*tmp = _root;
				node	*ret = _nil;

				while (tmp != _nil) {
					if (_comp(key, tmp->value)) {
						ret = tmp;
						tmp = tmp->left;
					}
					else
						tmp = tmp->right;
				}
				return (const_iterator(ret));
			}

			node*	search(const value_type& key) const {
				node	*tmp = NULL;

				tmp = search(_root, key);
				return (tmp);
			}

			// OBSERVER
			key_compare	key_comp() const {
				return (_comp);
			}

			// COMPARISON OPERATORS
			friend bool	operator==(const RBTree& lhs, const RBTree& rhs) {
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool	operator<(const RBTree& lhs, const RBTree& rhs) {
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

		private:
			void	insertFixup(node *child) {
				node	*uncle;

				if (child == _root || child->parent == _root)
					return ;
				while (child != _root && child->parent->color) {
					if (child->parent == child->parent->parent->left) {
						uncle = child->parent->parent->right;
						if (uncle != _nil && uncle->color) {
							child->parent->color = BLACK;
							uncle->color = BLACK;
							child->parent->parent->color = RED;
							child = child->parent->parent;
						}
						else {
							if (child == child->parent->right) {
								child = child->parent;
								leftRotation(child);
							}
							child->parent->color = BLACK;
							child->parent->parent->color = RED;
							rightRotation(child->parent->parent);
						} 
					}
					else {
						uncle = child->parent->parent->left;
						if (uncle != _nil && uncle->color) {
							child->parent->color = BLACK;
							uncle->color = BLACK;
							child->parent->parent->color = RED;
							child = child->parent->parent;
						}
						else {
							if (child == child->parent->left) {
								child = child->parent;
								rightRotation(child);
							}
							child->parent->color = BLACK;
							child->parent->parent->color = RED;
							leftRotation(child->parent->parent);
						}
					}
				}
				_root->color = BLACK;
				_nil->parent = _root;
			}

			void	deleteAll(node *tmp) {
				if (tmp == _nil || !tmp)
					return ;
				if (tmp->left != _nil)
					deleteAll(tmp->left);
				if (tmp->right != _nil)
					deleteAll(tmp->right);
				_node_alloc.destroy(tmp);
				_node_alloc.deallocate(tmp, 1);
				_size--;
				tmp = NULL;
			}

			void	deleteOne(node *toDelete)
			{
				node	*y, *x, *tmp;
				bool	y_color;

				y = toDelete;
				// if (toDelete == _nil)
				// 	return ;
				y_color = y->color;
				if (y->left == _nil) {
					x = y->right;
					transplant(y, y->right);
				}
				else if (y->right == _nil) {
					x = y->left;
					transplant(y, y->left);
				}
				else {
					tmp = y;
					y = findMin(tmp->right);
					y_color = y->color;
					x = y->right;
					if (y->parent == tmp)
						x->parent = y;
					else {
						transplant(y, y->right);
						y->right = tmp->right;
						tmp->right->parent = y;
					}
					transplant(tmp, y);
					y->left = tmp->left;
					y->left->parent = y;
					y->color = tmp->color;
				}
				_node_alloc.destroy(toDelete);
				_node_alloc.deallocate(toDelete, 1);
				_size--;
				if (!y_color)
					deleteFixup(x);
				_nil->parent = _root;
			}

			void	deleteFixup(node *x) {
				node	*w;

				while (x != _root && !x->color) {
					if (x == x->parent->left) {
						w = x->parent->right;
						if (w->color) {
							w->color = BLACK;
							x->parent->color = RED;
							leftRotation(x->parent);
							w = x->parent->right;
						}
						if (!w->left->color && !w->right->color) {
							w->color = RED;
							x = x->parent;
						}
						else {
							if (!w->right->color) {
								w->left->color = BLACK;
								w->color = RED;
								rightRotation(w);
								w = x->parent->right;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							leftRotation(x->parent);
							x = _root;
						}
					}
					else {
						w = x->parent->left;
						if (w->color) {
							w->color = BLACK;
							x->parent->color = RED;
							rightRotation(x->parent);
							w = x->parent->left;
						}
						if (!w->right->color && !w->left->color) {
							w->color = RED;
							x = x->parent;
						}
						else {
							if (!w->left->color) {
								w->right->color = BLACK;
								w->color = RED;
								leftRotation(w);
								w = x->parent->left;
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							rightRotation(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK;
			}

			void	rightRotation(node *x) {
				node	*y;

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


			node*	search(node *tmp, const value_type& key) const {
				if (!tmp || tmp == _nil || tmp->value == key)
					return (tmp);
				if (_comp(tmp->value, key))
					return search(tmp->right, key);
				else
					return search(tmp->left, key);
			}

			void	transplant(node *u, node *v) {
				if (u->parent == _nil)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			node*	findMin(node *tmp) const {
				if (!tmp || tmp == _nil)
					return (tmp);
				while (tmp->left != _nil)
					tmp = tmp->left;
				return (tmp);
			}

			node*	findMax(node *tmp) const {
				if (!tmp || tmp == _nil)
					return (tmp);
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
				std::cout << "min: " << tmp->value << "\n";
				tmp = findMax(_root);
				std::cout << "max: " << tmp->value << "\n";
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
				std::cout << "root key: " << tmp->value;
				std::cout.width(10); 
				std::cout << " | color: " << tmp->color << " | level: " << tmp->level << "\n";
				if (tmp->left != _nil) {
					std::cout.width(15);
					std::cout << "left key: " << tmp->left->value;
					std::cout.width(10);
					std::cout << " | color: " << tmp->left->color << " | level: " << tmp->left->level << "\n";
				}
				if (tmp->right != _nil) {
					std::cout.width(15);
					std::cout << "right key: " << tmp->right->value;
					std::cout.width(10);
					std::cout << " | color: " << tmp->right->color << " | level: " << tmp->right->level << "\n";
				}
				if (tmp->left != _nil)
					printNode(tmp->left);
				if (tmp->right != _nil)
					printNode(tmp->right);
			}

			// EXCEPTIONS
			class OutOfRange: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set.at() is out of range");
				}
			};

			class OutOfBounds: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set index is out of bounds");
				}
			};

			class EmptyContainer: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set is empty");
				}
			};

			class LengthError: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set begin is ahead of end");
				}
			};
	};
};

#endif