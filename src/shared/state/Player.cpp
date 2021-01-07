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


//Autres méthodes, à confirmer si on en a vraiment besoin
