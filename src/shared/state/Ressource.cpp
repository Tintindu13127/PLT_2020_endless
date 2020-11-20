#include "Ressource.h"

using namespace state;

Ressource::Ressource() {}
Ressource::~Ressource() {}

// Setter & Getters

int Ressource::getBrume(){
	return this->brume;
}
void Ressource::setBrume(int newBrume) {
	this->brume = newBrume;
}

int Ressource::getProd(){
	return this->production;
}
void Ressource::setProd(int newProd) {
	this->production = newProd;
}

int Ressource::getScience(){
	return this->science;
}
void Ressource::setScience(int newScience) {
	this->science = newScience;
}

int Ressource::getFood(){
	return this->food;
}
void Ressource::setFood(int newFood) {
	this->food = newFood;
}