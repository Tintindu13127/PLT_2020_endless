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
Player* State::getPlayer_a_ptr () {
	return &(this->player_a);
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

Player State::player_turn() {
	if (this->getTurn() % 2 == 0 ) {
		Player current_player = this->getPlayer_b();
		return current_player;
	}
	else {
		Player current_player = this->getPlayer_a();
		return current_player;
	}
}

const std::vector<SpaceCell>& State::getMap() const {
	return this->map;
}
void State::setMap(const std::vector<SpaceCell>& map) {
	this->map = map;
}

