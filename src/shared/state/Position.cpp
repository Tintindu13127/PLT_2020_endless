#include "Position.h"
#include <stdlib.h>

using namespace state;

// Constructeur & Destructeur

Position::Position() {
	this->setX(0);
	this->setY(0);
}
Position::Position(int x, int y){
	this->setX(x);
	this->setY(y);
}
Position::~Position(){}


//Setters & Getters

int Position::getX() const {
	return this->X;
}
void Position::setX(int X) {
	this->X = X;
}

int Position::getY() const {
	return this->Y;
}
void Position::setY(int Y){
	this->Y = Y;
}

bool Position::IsPosEqual(Position pos_target) {
	if (this->getX() == pos_target.getX() && this->getY() == pos_target.getY()) {
		return true;
	}
	else {
		return false;
	}
}

int Position::DistanceToTarget(Position pos_target) {
	int distance = abs(this->getX() - pos_target.getX()) + abs(this->getY() - pos_target.getY());
	return distance;
}
