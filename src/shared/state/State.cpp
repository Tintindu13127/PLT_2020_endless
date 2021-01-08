#include "State.h"

using namespace state;

State::State() {}
State::~State() {}

//Setters & Getters

const Player& State::getPlayer_a() const {
	return this->player_a;
}
void State::setPlayer_a(const Player& player_a) {
	this->player_a = player_a;
}

const Player& State::getPlayer_b() const {
	return this->player_b;
}
void State::setPlayer_b(const Player& player_b) {
	this->player_b = player_b;
}

int State::getTurn() const {
	return this->turn;
}
void State::setTurn(int turn) {
	this->turn = turn;
}

void State::IncrementTurn(){
	this->turn++;
}

const std::vector<SpaceCell>& State::getMap() const {
	return this->map;
}
void State::setMap(const std::vector<SpaceCell>& map) {
	this->map = map;
}

