#include "Position.h"

using namespace state;

// Constructeur & Destructeur

Position::Position() {
	this->X = 0;
	this->Y = 0;
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

