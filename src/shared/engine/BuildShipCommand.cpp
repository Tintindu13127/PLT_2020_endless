#include "BuildShipCommand.h"
#include <iostream>
#include <unistd.h> 

using namespace engine;
using namespace state;
using namespace std;


BuildShipCommand::BuildShipCommand (state::Ship& refShipTarget, state::StellarSystem& refStellarTarget) : ShipTarget(refShipTarget), StellarTarget(refStellarTarget)
{
    this->commandID = BUY_SHIP;
}


void execute (state::State& state)
{
    /*
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