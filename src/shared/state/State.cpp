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

void State::initMap() {
	int N = 8;
	int M = 8;
	int map[M][N];

	// Map de Test
	map[0][0] = 255;
	map[0][1] = 127;
	map[0][2] = 127;
	map[0][3] = 255;
	map[0][4] = 127;
	map[0][5] = 127;
	map[0][6] = 127;
	map[0][7] = 255;

	map[1][0] = 127;
	map[1][1] = 0;
	map[1][2] = 0;
	map[1][3] = 127;
	map[1][4] = 0;
	map[1][5] = 0;
	map[1][6] = 0;
	map[1][7] = 127;

	map[2][0] = 255;
	map[2][1] = 0; 
	map[2][2] = 0;
	map[2][3] = 127;
	map[2][4] = 0;
	map[2][5] = 0;
	map[2][6] = 0;
	map[2][7] = 127;

	map[3][0] = 127;
	map[3][1] = 0;
	map[3][2] = 0;
	map[3][3] = 127;
	map[3][4] = 0;
	map[3][5] = 0;
	map[3][6] = 0;
	map[3][7] = 127;

	map[4][0] = 127;
	map[4][1] = 0;
	map[4][2] = 0;
	map[4][3] = 255;
	map[4][4] = 127;
	map[4][5] = 255;
	map[4][6] = 127;
	map[4][7] = 255;

	map[5][0] = 127;
	map[5][1] = 0;
	map[5][2] = 0;
	map[5][3] = 0;
	map[5][4] = 0;
	map[5][5] = 127;
	map[5][6] = 0;
	map[5][7] = 0;

	map[6][0] = 255;
	map[6][1] = 127;
	map[6][2] = 127;
	map[6][3] = 127;
	map[6][4] = 127;
	map[6][5] = 255;
	map[6][6] = 0;
	map[6][7] = 0;

	map[7][0] = 0;
	map[7][1] = 0;
	map[7][2] = 0;
	map[7][3] = 0;
	map[7][4] = 0;
	map[7][5] = 0;
	map[7][6] = 0;
	map[7][7] = 0;

	// Création des éléments de la map
	std::vector<SpaceCell> map_ret;
	for (int n=0; n<8; n++) {
		for (int m=0; m<8; m++) {
			if (map[n][m] == 0){
				//auto voidcell = new SpaceCell(n, m, Void);
				map_ret.push_back(SpaceCell(n, m, Void));
				//free(voidcell);
			}
			if (map[n][m] == 127) {
				//auto waycell = new SpaceCell(n, m, StellarWay);
				map_ret.push_back(SpaceCell(n, m, StellarWay));
				//free(waycell);
			}
			if (map[n][m] == 255) {
				//auto systemcell = new SpaceCell(n, m, StellarSys);
				map_ret.push_back(SpaceCell(n, m, StellarSys));
				//free(systemcell);
			}
		}
	}
	this->setMap(map_ret);
}