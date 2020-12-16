#include "Position.h"

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

