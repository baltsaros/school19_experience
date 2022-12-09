#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "rbtree_iterator.hpp"
# include "map.hpp"
# define BLACK	false
# define RED	true

// colors: 0/false - Black; 1/true - Red

namespace ft {

	template <class Key, class Pair>
	struct Node {
		Key				key;
		Pair			value;
		bool			color;
		size_t			level;
		Node<Key, Pair>	*left;
		Node<Key, Pair>	*right;
		Node<Key, Pair>	*parent;

		Node(Node *parent) : color(BLACK), level(0),
			parent(parent), left(nullptr), right(nullptr) {}

		Node(Key k, Pair v, bool c, size_t lvl, Node *p, Node *l, Node *r) :
			key(k), value(v), color(c), level(lvl), parent(p), left(l), right(r) {}
	};

	template <class Key,
				class Pair,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<Pair> >
	class RBTree {
		public:
		// TYPEDEFS
			typedef Key							key_type;
			typedef Pair						value_type;
			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;
			typedef Compare						key_compare;
			typedef Allocator					allocator_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef Node<Key, Pair>				node;

			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::template rebind<Node<Key, value_type> >::other	alloc_node;
			
			typedef rbt_iterator<Key, Pair>				iterator;
			typedef rbt_iterator<Key, const Pair>		const_iterator;
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
				_alloc(alloc), _node_alloc(alloc), _comp(comp), _size(0) {
				// std::cout << "constructor 1" << std::endl;
				_root = nullptr;
				_nil = _node_alloc.allocate(1);
				_node_alloc.construct(_nil, node(_root));
			}

			RBTree(RBTree const &src) :
				_alloc(src._alloc), _node_alloc(src._alloc), _comp(src._comp), _size(0) {
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

			virtual ~RBTree() {
				// std::cout << "destructor\n";
				deleteAll();
			}

			void	copyTree(node *root, node *nil) {
				if (!_root) {
					node	*child;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(root->key, root->value, root->color, root->level, _nil, _nil, _nil));
					_root = child;
					_nil->parent = _root;
					_size++;
				}
				else {
					node	*child;
					node	*head = _root;
					node	*parent = _nil;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(root->key, root->value, root->color, root->level, nullptr, _nil, _nil));

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
					_size++;
				if (root->left != nil)
					copyTree(root->left, nil);
				if (root->right != nil)
					copyTree(root->right, nil);
			}

			pair<Key, bool>	insert(value_type pair) {
				if (!_root) {
					node	*child;

					child = _node_alloc.allocate(1);
					_node_alloc.construct(child, node(pair.first, pair, BLACK, 0, _nil, _nil, _nil));
					_root = child;
					_nil->parent = _root;
					_size++;
					return (make_pair(child->key, true));
				}

				node	*child;
				node	*head = _root;
				node	*parent = _nil;
				node	*tmp;

				tmp = search(pair.first);
				if (tmp != _nil) {
					std::cout << "Key is already present!\n";
					return (make_pair(pair.first, false));
				}
				child = _node_alloc.allocate(1);
				_node_alloc.construct(child, node(pair.first, pair, RED, 0, nullptr, _nil, _nil));

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
				_size++;
				insertFixup(child);
				return (make_pair(child->key, true));
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
				_nil->parent = _root;
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

			node*	search(Key key) {
				node	*tmp = nullptr;

				tmp = search(_root, key);
				return (tmp);
			}

			node*	search(node *tmp, Key key) {
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

			void	deleteOne(Key key) {
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
				_node_alloc.deallocate(toDelete, 1);
				_size--;
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
							}
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							rightRotation(x->parent);
							x = _root;
						}
					}
				}
			}

			node*	findMin(node *tmp) const {
				if (tmp == _nil)
					return (nullptr);
				while (tmp->left != _nil)
					tmp = tmp->left;
				return (tmp);
			}

			node*	findMax(node *tmp) const {
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
				std::cout << "root key: " << tmp->key << " | value: " << tmp->value.second;
				std::cout.width(10); 
				std::cout << " | color: " << tmp->color << " | level: " << tmp->level << "\n";
				if (tmp->left != _nil) {
					std::cout.width(15);
					std::cout << "left key: " << tmp->left->key << " | value: " << tmp->left->value.second;
					std::cout.width(10);
					std::cout << " | color: " << tmp->left->color << " | level: " << tmp->left->level << "\n";
				}
				if (tmp->right != _nil) {
					std::cout.width(15);
					std::cout << "right key: " << tmp->right->key << " | value: " << tmp->right->value.second;
					std::cout.width(10);
					std::cout << " | color: " << tmp->right->color << " | level: " << tmp->right->level << "\n";
				}
				if (tmp->left != _nil)
					printNode(tmp->left);
				if (tmp->right != _nil)
					printNode(tmp->right);
			}

			void	deleteAll() {
				deleteAll(_root);
				_root = nullptr;
				_node_alloc.deallocate(_nil, 1);
				_nil = nullptr;
			}

			void	deleteAll(node *tmp) {
				if (tmp == _nil || !tmp)
					return ;
				if (tmp->left != _nil)
					deleteAll(tmp->left);
				if (tmp->right != _nil)
					deleteAll(tmp->right);
				_node_alloc.deallocate(tmp, 1);
				_size--;
				tmp = nullptr;
			}

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
	};
}

#endif