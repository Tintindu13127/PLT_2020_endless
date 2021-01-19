#include "BuildShipCommand.h"
#include <iostream>
#include <unistd.h> 

using namespace engine;
using namespace state;
using namespace std;


BuildShipCommand::BuildShipCommand (state::Ship_TypeID& refShipID, state::StellarSystem& refStellarTarget) : ShipID(refShipID), StellarTarget(refStellarTarget)
{
    this->commandID = BUY_SHIP;
}


void execute (state::State& state)
{
    /*
    Player player = state.player_turn();
    std::vector<Ship> list_ship = player.getList_ship();

    for( unsigned int i =0; i < list_ship.size(); i++)
    {
        if(list_ship[i].IsPosEgal(StellarTarget.getPosition()))
        {
            cout << " achat du vaisseau " << endl;
            // on ajoute le vaisseaux à la liste du joueur
            Playplayerer.addShip(ShipTarget);
            // on initialise le vaisseau sur le system actuelle 
            Ship(ShipID,StellarTarget.getPosition());
        }
    }

    cout << " Vous ne pouvez pas achetez de vaisseau sur ce stellar system " << endl;
    
    // on récupère le prix de l'achat du vaisseaux ( food, brume et prod)
    brumePrice = ShipTarget.getbrumeprice();
    foodPrice = ShipTarget.getFoodprice();
    prodPrice = ShipTarget.getProductionprice();
    //on récupere les ressources actuelles du joueurs
    brume = Ressources.getBrume();
    food = Ressources.getFood();
    prod = Ressource.getProduction();
    if(brume >= brumePrice and food >= foodPrice and prod >= prodPrice)
    {
        cout << " achat du vaisseau " << endl;
        // on ajoute le vaisseaux à la liste du joueur
        Player.addShip(ShipTarget);
        // on initialise le vaisseau sur le system actuelle 
        Ship(SHipid, x, y)
    }
    else
    {
        cout << " Vous n'avez pas les ressources pour acheter ce vaisseaux " << endl;
    }
    */
}
Json::Value BuildShipCommand::serialize ()
{
    Json::Value newCommand;
    newCommand["id"] = this-> commandID;
    return newCommand;
}