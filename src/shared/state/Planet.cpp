#include "Planet.h"

using namespace state;

int Planet::instance_count =0;

//Constructor + Destructor
Planet::Planet() {
	this->planetID = instance_count++;
	StatutID statut = (StatutID)1 ;
	this->statut = statut;
}
Planet::~Planet() {}

//Setters & getters

SizeID Planet::getSize_p() const{
	return this->size_p;
}
void Planet::setSize_p(SizeID size_p){
	this->size_p = size_p;
}

Type_planetID Planet::getType() const {
	return this->type;
}
void Planet::setType(Type_planetID type) {
	this->type = type;
}

StatutID Planet::getStatut() const {
	return this->statut;
}
void Planet::setStatut(StatutID statut) {
	this->statut = statut;
}

int Planet::getPlanetID() const {
	return this->planetID;
}
void Planet::setPlanetID(int planetID) {
	this->planetID = planetID;
}