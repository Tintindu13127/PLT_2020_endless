#include "Objet.h"

using namespace state;

// Constructeur & destructeur
Objet::Objet() {
	std::string element_name;
	Position initial_position;
	this->name = element_name;
	this->position = initial_position;
}
Objet::~Objet() {}

// Setters & Getters

const std::string& Objet::getName() const {
	return this->name;
}
void Objet::setName(const std::string& name) {
	this->name = name;
}


const Position& Objet::getPosition() const {
	return this->position;
}
void Objet::setPosition(const Position& position){
	this->position = position;
}