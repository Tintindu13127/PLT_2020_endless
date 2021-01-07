#include "Ressource.h"

using namespace state;

Ressource::Ressource(){
	
}
Ressource::Ressource(int brume, int prod, int food) {
	this->setBrume(brume);
	this->setProd(prod);
	this->setFood(food);
}
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

int Ressource::getFood(){
	return this->food;
}
void Ressource::setFood(int newFood) {
	this->food = newFood;
}