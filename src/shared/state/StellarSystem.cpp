#include "StellarSystem.h"

using namespace state;

int StellarSystem::instance_count = 0;

//Constructeur + destructeur
StellarSystem::StellarSystem() {
	this->IsCaptured = false;
	this->systemID = instance_count++;
	// this->planet_list.push_back(new_planet); ajouter au constructeur un argument planet ?
	// this->building_list.push_back(new_building); same
}

StellarSystem::~StellarSystem() {}

// Setters et getters


const std::string& StellarSystem::getOwner() const {
	return this->owner;
}
void StellarSystem::setOwner(const std::string& owner) {
	this->owner = owner;
}

bool StellarSystem::getIsCaptured() const {
	return this->IsCaptured;
}
void StellarSystem::setIsCaptured(bool IsCaptured) {
	this->IsCaptured = IsCaptured;
}

int StellarSystem::getSystemID() const {
	return this->systemID;
}
void StellarSystem::setSystemID(int systemID) {
	this->systemID = systemID;
}

const std::vector<Building>& StellarSystem::getBuilding_list() const { 
	return this->building_list;
}
void StellarSystem::setBuilding_list(const std::vector<Building>& building_list) {
	this->building_list = building_list;
}

//Autres méthodes

void StellarSystem::build_building(Building building) {
	this->building_list.push_back(building);
	// faire perdre de l'argent au joueur, la nourriture et la production
}


void StellarSystem::colonize() {
	this->setIsCaptured(true);
} 


