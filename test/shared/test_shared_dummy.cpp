
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Ship.h"
#include "../../src/shared/state/StellarSystem.h"


using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestState)
{

	// Ship
	auto ship_1 = new Ship(); // equivalent à Ship* ship_1 = new Ship();
	auto ship_2 = new Ship();

	// Level setter
	int level = 1;
    ship_1->setLevel(level);
    BOOST_CHECK_EQUAL(ship_1->getLevel(), level); 
	
	// Experience setter
	int experience = 0;
    ship_1->setExperience(experience);
    BOOST_CHECK_EQUAL(ship_1->getExperience(), experience); 

	// Price setter
	int price = 10;
    ship_1->setPrice(price);
    BOOST_CHECK_EQUAL(ship_1->getPrice(), price); 

	// Production setter
	int production = 10;
    ship_1->setProduction_cost(price);
    BOOST_CHECK_EQUAL(ship_1->getProduction_cost(), production); 

	// Ship's stats setter
	ShipStats stats;
	stats.attack_point = 5;
	stats.defense_point = 2;
	stats.health = 7;
	stats.movement_point = 2;
    ship_1->setShip_stats(stats);
    BOOST_CHECK_EQUAL(ship_1->getShip_stats().attack_point, stats.attack_point); 
    BOOST_CHECK_EQUAL(ship_1->getShip_stats().defense_point, stats.defense_point); 
    BOOST_CHECK_EQUAL(ship_1->getShip_stats().health, stats.health); 
    BOOST_CHECK_EQUAL(ship_1->getShip_stats().movement_point, stats.movement_point); 

	ShipStats stats_2;
	stats_2.attack_point = 4;
	stats_2.defense_point = 3;
	stats_2.health = 7;
	stats_2.movement_point = 2;
    ship_2->setShip_stats(stats_2);

	// Attack method
	ship_1->attack(ship_2);
    BOOST_CHECK_EQUAL(ship_1->getShip_stats().health, 5); 
    BOOST_CHECK_EQUAL(ship_2->getShip_stats().health, 5); 

	// LevelUp method
	ship_1->LevelUp();
	BOOST_CHECK_EQUAL(ship_1->getLevel(), 2);


	//StellarSystem
	auto system = new StellarSystem();

	//Nb_planets setter
	int nb_planets = 2;
	system->setNb_planets(nb_planets);
	BOOST_CHECK_EQUAL(system->getNb_planets(), nb_planets);

	//Owner setter
	const std::string owner = "Hugo";
	system->setOwner(owner);
	BOOST_CHECK_EQUAL(system->getOwner(), owner);

	//IsCaptured setter
	bool isCaptured = false;
	system->setIsCaptured(isCaptured);
	BOOST_CHECK_EQUAL(system->getIsCaptured(), isCaptured);

	//SystemID setter
	int systemID = 4;
	system->setSystemID(systemID);
	BOOST_CHECK_EQUAL(system->getSystemID(), systemID);

	//Planet_list setter
	auto planet1 = new Planet();
	auto planet2 = new Planet();
	const std::vector<Planet>& planet_list = {planet1, planet2};
	system->setPlanet_list(planet_list);
	const std::vector<Planet>& planet_list_getted = system->getPlanet_list();
//	BOOST_CHECK_EQUAL(planet_list_getted[0], *planet1);
	//BOOST_CHECK(planet_list_getted[1] == planet2);

	//add Planet to Planet_list
	auto planet3 = new Planet();
	system->add_planet_list(*planet3);
}
 /*vim: set sw=2 sts=2 et : */
