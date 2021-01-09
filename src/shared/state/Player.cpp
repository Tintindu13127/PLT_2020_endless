#include "Player.h"

using namespace state;

int Player::instance_count = 0;

Player::Player() {
	this->player_id = instance_count++;
}
Player::~Player() {}

//Setters & Getters

const Ressource& Player::getRessources() const {
	return this->ressources;
}
void Player::setRessources(const Ressource& ressources) {
	this->ressources = ressources;
}

const std::vector<Ship>& Player::getList_ship() const{
	return this->list_ship;
}
void Player::setList_ship(const std::vector<Ship>& list_ship) {
	this->list_ship = list_ship;
}

const std::vector<StellarSystem>& Player::getList_stellarSystem() const{
	return this->list_stellarSystem;
}
void Player::setList_stellarSystem(const std::vector<StellarSystem>& list_stellarSystem) {
	this->list_stellarSystem = list_stellarSystem;
}

bool Player::getIsTurn() const {
	return this->isTurn;
}
void Player::setIsTurn(bool isTurn) {
	this->isTurn = isTurn;
}

int Player::getProduction_prod() const {
	return this->production_prod;
}
void Player::setProduction_prod(int production_prod) {
	this->production_prod = production_prod;
}

int Player::getBrume_prod() const {
	return this->brume_prod;
}
void Player::setBrume_prod(int brume_prod) {
	this->brume_prod= brume_prod;
}

int Player::getFood_prod() const {
	return this->food_prod;
}
void Player::setFood_prod(int food_prod){
	this->food_prod = food_prod;
}

void Player::addShip(Ship ship) {
	this->list_ship.push_back(ship);
}
void Player::addStellarSystem(StellarSystem stellarSystem) {
	this->list_stellarSystem.push_back(stellarSystem);
}

int Player::getPlayer_id() const {
	return this->player_id;
}
void Player::setPlayer_id(int player_id) {
	this->player_id = player_id;
}
//Autres méthodes, à confirmer si on en a vraiment besoin
