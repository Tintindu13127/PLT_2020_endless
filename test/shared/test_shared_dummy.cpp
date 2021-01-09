
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Ship.h"
#include "../../src/shared/state/StellarSystem.h"
#include "../../src/shared/state/Player.h"
#include "../../src/shared/state/Objet.h"
#include "../../src/shared/state/State.h"


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

	// Test add_MoveShipMap
	/*Position *ship_pos = new Position(2,2);
	ship_1->setPosition(*ship_pos);
	ship_1->add_MoveShipMap();
	const std::vector<std::pair<int, int>> moveship1map = ship_1->getMoveShip_map();*/
	/*std::pair<int, int> pos1 = std::make_pair(2, 3);
	BOOST_CHECK_EQUAL(moveship1map[0], pos1);*/

//--------------------------------------------------------
//					StellarSystem
//--------------------------------------------------------	
	auto system = new StellarSystem();

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
	
	//Building_list setter
	Building building0;
	Building building1;
	std::vector<Building> building_list	= {building0, building1};
	system->setBuilding_list(building_list);
	const std::vector<Building>& building_list_gotten = system->getBuilding_list();
	BOOST_CHECK_EQUAL(building_list_gotten[0].getBuildingID(), building0.getBuildingID());
	BOOST_CHECK_EQUAL(building_list_gotten[1].getBuildingID(), building1.getBuildingID());

	// Type
	Type_StellarSystemID type1 = cold;
	system->setType(type1);
	BOOST_CHECK_EQUAL(system->getType(), type1);

	// Size_stellarsystem
	SizeID size1 = small;
	system->setSize_ss(size1);
	BOOST_CHECK_EQUAL(system->getSize_ss(), size1);

	// Statut
	StatutID statut1 = colonized;
	system->setStatut(statut1);
	BOOST_CHECK_EQUAL(system->getStatut(), statut1); 

	// Prod
	int brume_prod = 2;
	int food_prod = 3;
	int production_prod = 5;
	system->setBrume_prod(brume_prod);
	system->setFood_prod(food_prod);
	system->setProduction_prod(production_prod);
	BOOST_CHECK_EQUAL(system->getBrume_prod(), brume_prod);
	BOOST_CHECK_EQUAL(system->getFood_prod(), food_prod);
	BOOST_CHECK_EQUAL(system->getProduction_prod(), production_prod);

	// Colonize
	system->colonize();
	BOOST_CHECK_EQUAL(system->getIsCaptured(), true);


	//add Planet by build_building() method
	Building building2;
	system->build_building(building2);
    BOOST_CHECK_EQUAL(building_list_gotten[2].getBuildingID(), 2);

//--------------------------------------------------------
//					Building
//--------------------------------------------------------	
	//building_price
	building0.setBrume_price(5);
	building0.setProduction_price(3);
	building0.setFood_price(2);
	BOOST_CHECK_EQUAL(building0.getBrume_price(), 5);
	BOOST_CHECK_EQUAL(building0.getProduction_price(), 3);
	BOOST_CHECK_EQUAL(building0.getFood_price(), 2);

	//building_production
	building0.setProd_quantity(6);
	BOOST_CHECK_EQUAL(building0.getProd_quantity(), 6);

	//buildingID
	building0.setBuildingID(36);
	BOOST_CHECK_EQUAL(building0.getBuildingID(), 36);

//--------------------------------------------------------
//					Ressource
//--------------------------------------------------------
	//Constructeur initial, il appelle les setters, permet de tester donc setters et getters
	Ressource *ressource_init = new Ressource(10,2,1); //auto *ressource_init...
	BOOST_CHECK_EQUAL(ressource_init->getBrume(), 10);
	BOOST_CHECK_EQUAL(ressource_init->getProd(), 2);
	BOOST_CHECK_EQUAL(ressource_init->getFood(), 1);

//--------------------------------------------------------
//					Player
//--------------------------------------------------------
	Player Hugo;

	//Ressources, test uniquement sur Brume par exemple suffit
	Hugo.setRessources(*ressource_init);
	Ressource hugo_ressources = Hugo.getRessources();
	BOOST_CHECK_EQUAL(ressource_init->getBrume(), hugo_ressources.getBrume());

	//List_StellarSystem
	std::vector<StellarSystem> stellarsystem_list = {*system};
	Hugo.setList_stellarSystem(stellarsystem_list);
	StellarSystem system_gotten = Hugo.getList_stellarSystem()[0];
	BOOST_CHECK_EQUAL(system_gotten.getSystemID(), 4);

	//isTurn
	Hugo.setIsTurn(true);
	BOOST_CHECK_EQUAL(Hugo.getIsTurn(), true);

	//List_ship setter
	std::vector<Ship> ship_list	= {*ship_1, *ship_2};
	Hugo.setList_ship(ship_list);
	const std::vector<Ship>& ship_list_gotten = Hugo.getList_ship();
	BOOST_CHECK_EQUAL(ship_list_gotten[0].getShipID(), ship_1->getShipID());
	BOOST_CHECK_EQUAL(ship_list_gotten[1].getShipID(), ship_2->getShipID());

	//addShip
	auto ship_3 = new Ship();
	Hugo.addShip(*ship_3);
	BOOST_CHECK_EQUAL(Hugo.getList_ship()[2].getShipID(), ship_3->getShipID());

	//addStellarSystem
	auto system2 = new StellarSystem();
	Hugo.addStellarSystem(*system2);
	BOOST_CHECK_EQUAL(Hugo.getList_stellarSystem()[1].getSystemID(), system2->getSystemID());


//--------------------------------------------------------
//					State
//--------------------------------------------------------
	//Player
	auto state = new State();
	state->setPlayer_a(Hugo);
	Hugo.setPlayer_id(12);
	BOOST_CHECK_EQUAL(Hugo.getPlayer_id(), 12);

	// Turn
	state->setTurn(10);
	BOOST_CHECK_EQUAL(state->getTurn(), 10);
	state->IncrementTurn();
	BOOST_CHECK_EQUAL(state->getTurn(), 11);

}
 /*vim: set sw=2 sts=2 et : */
