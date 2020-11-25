#include "Ship.h"

using namespace state;

Ship::Ship(Ship_TypeID ship) {
	this->price = 10;
	this->production_cost = 10;
	this->level = 0;
	this->experience = 0;
}

Ship::~Ship() {}

//Setters & Getters

int Ship::getLevel() const { 
	return level; 
}
void Ship::setLevel(int level) {
	this->level = level ;
}

int Ship::getExperience() const {
	return this->experience;
}
void Ship::setExperience(int experience) {
	this->experience = experience;
}

int Ship::getPrice() const {
	return this->price;
}
void Ship::setPrice(int price) {
	this->price = price;
}

int Ship::getProduction_cost() const {
	return this->production_cost;
}
void Ship::setProduction_cost(int production_cost) {
	this->production_cost = production_cost;
}

Ship_TypeID Ship::getType_ship() const {
	return this->type_ship;
}
void Ship::setType_ship(Ship_TypeID type_ship) {
	this->type_ship = type_ship;
}

const ShipStats& Ship::getShip_stats() const {
	return this->ship_stats;
}
void Ship::setShip_stats(const ShipStats& ship_stats) {
	this->ship_stats = ship_stats;
}

// Operations
void receiveDamages(int damage_point) {
	this->setShip_stats.health = this->setShip_stats.health - 1;
}
void Ship::attack(Ship* ship_target) {

}

void Ship::moveShip(){}

void Ship::LevelUp() {
	this->setLevel(this->level +1);
}




