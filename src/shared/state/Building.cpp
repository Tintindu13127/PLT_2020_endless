#include "Building.h"

using namespace state;

int Building::instance_count = 0;

Building::Building() {
	this->buildingID = instance_count++;
}
Building::~Building() {}

// Setters & getters

int Building::getBrume_price() const {
	return this->brume_price;
}
void Building::setBrume_price(int brume_price) {
	this->brume_price = brume_price;
}

int Building::getProduction_price() const {
	return this->production_price;
}
void Building::setProduction_price(int production_price){
	this->production_price = production_price;
}

int Building::getFood_price() const {
	return this->food_price;
}
void Building::setFood_price(int food_price){
	this->food_price = food_price;
}

int Building::getBuildingID() const {
	return this->buildingID;
}
void Building::setBuildingID(int buildingID) {
	this->buildingID = buildingID;
}

Ressources Building::getProd_type() const {
	return this->prod_type;
}
void Building::setProd_type(Ressources prod_type) {
	this->prod_type = prod_type;
}



// Others methods
