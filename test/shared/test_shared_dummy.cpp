
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Ship.h"
#include "../../src/shared/state/StellarSystem.h"
#include "../../src/shared/state/Player.h"


using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestState)
{

//--------------------------------------------------------
//					Ship
//--------------------------------------------------------	
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

//--------------------------------------------------------
//					StellarSystem
//--------------------------------------------------------	
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
	Planet planet0;
	Planet planet1;
	std::vector<Planet> planet_list	= {planet0, planet1};
	system->setPlanet_list(planet_list);
	const std::vector<Planet>& planet_list_getted = system->getPlanet_list();

	BOOST_CHECK_EQUAL(planet_list_getted[0].getPlanetID(), planet0.getPlanetID());
	BOOST_CHECK_EQUAL(planet_list_getted[1].getPlanetID(), planet1.getPlanetID());

	//add Planet to Planet_list
	Planet planet2;
	system->add_planet_list(planet2);
    BOOST_CHECK_EQUAL(planet_list_getted[2].getPlanetID(), 2);
	//Colonize()
	BOOST_CHECK_EQUAL(planet0.getStatut(), true);
	
	//Building_list setter
	Building building0;
	Building building1;
	std::vector<Building> building_list	= {building0, building1};
	system->setBuilding_list(building_list);
	const std::vector<Building>& building_list_getted = system->getBuilding_list();
	BOOST_CHECK_EQUAL(building_list_getted[0].getBuildingID(), building0.getBuildingID());
	BOOST_CHECK_EQUAL(building_list_getted[1].getBuildingID(), building1.getBuildingID());

	//add Planet by buy_building() method
	Building building2;
	system->buy_building(building2);
    BOOST_CHECK_EQUAL(building_list_getted[2].getBuildingID(), 2);

//--------------------------------------------------------
//					Planet
//--------------------------------------------------------	
	//PlanetID
	planet0.setPlanetID(20);
	BOOST_CHECK_EQUAL(planet0.getPlanetID(), 20);

	//Size_planet
	SizeID size_planet = (SizeID)2;
	planet0.setSize_p(size_planet);
	BOOST_CHECK_EQUAL(planet0.getSize_p(), size_planet);

	//planet_type
	Type_planetID planet_type = (Type_planetID)3;
	planet0.setType(planet_type);
	BOOST_CHECK_EQUAL(planet0.getType(), planet_type);

	//planet_statut
	StatutID planet_statut = (StatutID)2;
	planet0.setStatut(planet_statut);
	BOOST_CHECK_EQUAL(planet0.getStatut(), planet_statut);

//--------------------------------------------------------
//					Building
//--------------------------------------------------------	
	//building_price
	building0.setPrice(5);
	BOOST_CHECK_EQUAL(building0.getPrice(), 5);

	//building_production
	building0.setProduction(6);
	BOOST_CHECK_EQUAL(building0.getProduction(), 6);

	//buildingID
	building0.setBuildingID(36);
	BOOST_CHECK_EQUAL(building0.getBuildingID(), 36);

	// turnLeft(), A MODIFIER QUAND ELLE SERA CODER
	int turn = building0.turnLeft();
	BOOST_CHECK_EQUAL(turn, 0);

//--------------------------------------------------------
//					Ressource
//--------------------------------------------------------
	//Constructeur initial, il appelle les setters, permet de tester donc setters et getters
	Ressource *ressource_init = new Ressource(10,2,2,1); //auto *ressource_init...
	BOOST_CHECK_EQUAL(ressource_init->getBrume(), 10);
	BOOST_CHECK_EQUAL(ressource_init->getProd(), 2);
	BOOST_CHECK_EQUAL(ressource_init->getScience(), 2);
	BOOST_CHECK_EQUAL(ressource_init->getFood(), 1);

	//


//--------------------------------------------------------
//					Player
//--------------------------------------------------------
	//Player Hugo;

	//Ressources
	//Hugo.setRessources()

}
 /*vim: set sw=2 sts=2 et : */
