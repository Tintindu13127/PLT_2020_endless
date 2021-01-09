#include "SpaceCell.h"
#include "State.h"
#include "Position.h"

using namespace state;

int SpaceCell::instance_count = 0;

SpaceCell::SpaceCell(int newX, int newY, CellTypeId cellType) {
	this->instance_count++;
}
SpaceCell::~SpaceCell() {}

int SpaceCell::getCellID() const {
	return this->cellID;
}
void SpaceCell::setCellID(int cellID) {
	this->cellID = cellID;
}

CellTypeId SpaceCell::getCellTypeId() const {
	return this->cellTypeId;
}
void SpaceCell::setCellTypeId(CellTypeId cellTypeId) {
	this->cellTypeId = cellTypeId;
}

bool SpaceCell::isOccupied (State& state) { 
	Position cell_pos = this->getPosition();
	for (auto current_player : {state.getPlayer_a(), state.getPlayer_b()} ){
		for (auto ship : current_player.getList_ship()) {
			Position ship_position = ship.getPosition();
			if((ship_position.getX() == cell_pos.getX()) && (ship_position.getY() == cell_pos.getY())){
				return true;
			}
		}
	}
	return false;	
}

bool SpaceCell::isOccupiedbyAlly (State& state) {
	//Position cell_pos = this->getPosition();

	return false;
}
