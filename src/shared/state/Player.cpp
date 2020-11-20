#include "Player.h"

using namespace state;

Player::Player() {}
Player::~Player() {}

//Setters & Getters

const Ressource& Player::getRessources() const {
	return this->ressources;
}
void Player::setRessources(const Ressource& ressources) {
	this->ressources = ressources;
}

const Ship& Player::getShip() const {
	return this->ship;
}
void Player::setShip(const Ship& ship) {
	this->ship = ship;
}

const StellarSystem& Player::getStellarSystem() const {
	return this->stellarSystem;
}
void Player::setStellarSystem(const StellarSystem& stellarSystem) {
	this->stellarSystem = stellarSystem;
}

bool Player::getIsTurn() const {
	return this->isTurn;
}
void Player::setIsTurn(bool isTurn) {
	this->isTurn = isTurn;
}

const std::vector<int>& Player::getMoveShip_map() const {
	return this->moveShip_map;
}
void Player::setMoveShip_map(const std::vector<int>& moveShip_map) {
	this->moveShip_map = moveShip_map;
}

const std::vector<Ship>& Player::getShip_list() const {
	return this->ship_list;
}
void Player::setShip_list(const std::vector<Ship>& ship_list) {
	this->ship_list = ship_list;
}

//Autres méthodes, à confirmer si on en a vraiment besoin
