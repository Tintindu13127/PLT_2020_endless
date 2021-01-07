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

Type_StellarSystemID StellarSystem::getType() const {
	return this->type;
}
void StellarSystem::setType(Type_StellarSystemID type) {
	this->type = type;
}

SizeID StellarSystem::getSize_ss() const {
	return this->size_ss;
}
void StellarSystem::setSize_ss(SizeID size_ss) {
	this->size_ss = size_ss;
}

StatutID StellarSystem::getStatut() const {
	return this->statut;
}
void StellarSystem::setStatut(StatutID statut) {
	this->statut = statut;
}

int StellarSystem::getProduction_prod() const {
	return this->production_prod;
}
void StellarSystem::setProduction_prod(int production_prod) {
	this->production_prod = production_prod;
}

int StellarSystem::getBrume_prod() const {
	return this->brume_prod;
}
void StellarSystem::setBrume_prod(int brume_prod) {
	this->brume_prod= brume_prod;
}

int StellarSystem::getFood_prod() const {
	return this->food_prod;
}
void StellarSystem::setFood_prod(int food_prod){
	this->food_prod = food_prod;
}

//Autres méthodes

void StellarSystem::build_building(Building building) {
	this->building_list.push_back(building);
	// faire perdre de l'argent au joueur, la nourriture et la production
}


void StellarSystem::colonize() {
	this->setIsCaptured(true);
} 


