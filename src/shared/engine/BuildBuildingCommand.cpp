#include "BuildBuildingCommand.h"
#include <iostream>
#include <unistd.h> 

using namespace engine;
using namespace state;
using namespace std;


BuildBuildingCommand::BuildBuildingCommand (state::Building& refBuildingTarget, state::StellarSystem& refStellarTarget) : BuildingTarget(refBuildingTarget), StellarTarget(refStellarTarget)
{
    this->commandID = BUILD_BUILDING;
}


void execute (state::State& state)
{
    /*
    // on récupère le prix de l'achat du vaisseaux ( food, brume et prod)
    brumePrice = BuildTarget.getbrume_price();
    foodPrice = BuildTarget.getFood_price();
    prodPrice = BuildTarget.getProducion_price();
    //on récupere les ressources acuelle_s du joueurs
    brume = Ressources.getBrume();
    food = Ressources.getFood();
    prod = Ressource.getProduction();
    if(brume >= brumePrice and food >= foodPrice and prod >= prodPrice)
    {
        cout << " construction du batiment " << endl;
        // on ajoute le building à la liste du joueur
        Player.addBuilding(BuildTarget)
        // on initialise le building sur le system actuelle 
        Building(buildid, stellartarget );

    }
    else
    {
        cout << " Vous n'avez pas les ressources pour construire ce building" << endl;
    }
    */
}
Json::Value BuildBuildingCommand::serialize ()
{
    Json::Value newCommand;
    newCommand["id"] = this-> commandID;
    return newCommand;
}