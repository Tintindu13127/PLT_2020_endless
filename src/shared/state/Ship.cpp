#include "Ship.h"
#include <iostream>

using namespace std;
using namespace state;

int Ship::instance_count = 0;

Ship::Ship(){
	this->price = 10;
	this->production_cost = 10;
	this->level = 0;
	this->experience = 0;
	this->shipID = instance_count++;
}

Ship::Ship(Ship_TypeID type_ship) {
	if (type_ship == 3){
		
	}
	this->price = 10;
	this->production_cost = 10;
	this->level = 0;
	this->experience = 0;
	this->shipID = instance_count++;
}

Ship::~Ship() {}

//Setters & Getters

int Ship::getShipID() const {
	return this->shipID;
}
void Ship::setShipID(int shipID) {
	this->shipID = shipID;
}

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
void Ship::receiveDamages(int damage_point) { // TO DO utiliser une exception au moment de la destruction
	int hp = this->ship_stats.health ;
	if (hp<damage_point){
		cout <<"Ship must be destroyed" << endl;
		this->ship_stats.health = 0;
	}
	else {
		this->ship_stats.health = hp - damage_point;
	}
}

void Ship::attack(Ship* ship_target) {
	int damage_target;
	int damage_attacker;
	damage_target = this->ship_stats.attack_point - ship_target->ship_stats.defense_point;
	damage_attacker = ship_target->ship_stats.attack_point - this->ship_stats.defense_point; 

	ship_target->receiveDamages(damage_target);
	this->receiveDamages(damage_attacker);
}

void Ship::moveShip(){} // Is it a command for the engine ? 

void Ship::LevelUp() {
	this->setLevel(this->level +1);
}




