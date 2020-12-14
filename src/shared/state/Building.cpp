#include "Building.h"

using namespace state;

int Building::instance_count = 0;

Building::Building() {
	this->buildingID = instance_count++;
}
Building::~Building() {}

// Setters & getters

int Building::getPrice() const {
	return this->price;
}
void Building::setPrice(int price) {
	this->price = price;
}

int Building::getProduction() const {
	return this->production;
}
void Building::setProduction(int production){
	this->production = production;
}

int Building::getBuildingID() const {
	return this->buildingID;
}
void Building::setBuildingID(int buildingID) {
	this->buildingID = buildingID;
}

// Others methods
int Building::turnLeft() {
	return 0;
}