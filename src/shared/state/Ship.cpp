#include "Ship.h"
#include "State.h"
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

int Ship::getMovement_left() const {
	return this->movement_left;
}
void Ship::setMovement_left(int movement_left) {
	this->movement_left = movement_left;
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

void Ship::LevelUp() {
	this->setLevel(this->level +1);
}

const std::vector<SpaceCell>& Ship::getMoveShip_map() const {
	return this->moveShip_map;
}
void Ship::setMoveShip_map(const std::vector<SpaceCell>& moveShip_map) {
	this->moveShip_map = moveShip_map;
}

std::vector<SpaceCell> Ship::proximityCell (State& state1) { //Renvoi la liste des SpaceCells à proximité
	std::vector<SpaceCell> proximityCell_tab;
	Position ship_pos = this->getPosition();
	int ship_x = ship_pos.getX();
	int ship_y = ship_pos.getY();
	std::vector<SpaceCell> map = state1.getMap();

	for (auto spaceCell : map){
		Position cell_pos = spaceCell.getPosition() ;
		if ((cell_pos.getX() == ship_x) && (cell_pos.getY() == ship_y + 1)) {
			proximityCell_tab.push_back(spaceCell);
		}
		else if ((cell_pos.getX() == ship_x && cell_pos.getY() == ship_y - 1))
		{
			proximityCell_tab.push_back(spaceCell);
		}
		else if ((cell_pos.getX() == ship_x + 1) && (cell_pos.getY() == ship_y))
		{
			proximityCell_tab.push_back(spaceCell);
		}
		else if ((cell_pos.getX() == ship_x - 1) && (cell_pos.getY() == ship_y))
		{
			proximityCell_tab.push_back(spaceCell);
		}
	}
	return proximityCell_tab;
}

void Ship::add_MoveShipMap(State& state){ // Actualise la liste des SpaceCells où le Ship peut se rendre
	this->moveShip_map.clear();
	int pm = this->movement_left;
	std::vector<SpaceCell> proximity_list;
	for (int j=0; j<pm; j++){
		proximity_list = this->proximityCell(state);
		for (int i =0 ; i<4 ; i++) {
			if (proximity_list[i].getCellTypeId() != Void) { //Les cases "Void" ne sont pas des cases où l'on peut aller
				this->moveShip_map.push_back(proximity_list[i]);
			}
			proximity_list.pop_back(); // permet de reset proximity_list avant le rappel de proximity_Cell()
		}
	}
	



}


