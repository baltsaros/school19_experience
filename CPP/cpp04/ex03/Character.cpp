#include "include/Character.hpp"

//	CONSTRUCTORS
Character::Character(void) {
	std::cout << CYNB "A character was born!" NC << std::endl;
	this->_name = "noname";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string const & name) {
	std::cout << CYNB "Character was born!" NC << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(Character const &src) {
	std::cout << CYN "Copy Character" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Character::~Character(void) {
	std::cout << REDB "UnCharacter" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Character&	Character::operator=(Character const &rhs) {
	std::cout << CYN "Assigning Character" NC << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
		for (int i = 0; i < 4; i++) {
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

//	OTHERS
std::string const &	Character::getName(void) const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return ;
		}
	}
	return ;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4){
		std::cout << this->getName() << " drops " << this->_inventory[idx]->getType();
		std::cout << " on the floor." << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "Unequip: invalid index" << std::endl;
	return ;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4){
		std::cout << this->getName() << " is casting " << this->_inventory[idx]->getType();
		std::cout << " magic" << std::endl;
		this->_inventory[idx]->use(target);
	}
	else
		std::cout << "Invalid index" << std::endl;
	return ;
}

void	Character::showEquip(void) const {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			std::cout << this->_name << " has ";
			std::cout << this->_inventory[i]->getType();
			std::cout << " in the equipement." << std::endl;
		}
	}
	return ;
}