#include "ColonizeCommand.h"
#include <iostream>
#include <unistd.h> 

using namespace engine;
using namespace state;
using namespace std;


ColonizeCommand::ColonizeCommand (state::Ship& refShipTarget, state::StellarSystem& refStellarTarget) : ShipTarget(refShipTarget), StellarTarget(refStellarTarget)
{
    this->commandID = COLONIZE;
}


void execute (state::State& state)
{
    cout << "colonize action " << endl;
    // on vérifie que le vaisseau à tous ses points de mouvement
    /*if(ShipTarget.getMovement_left() == 3)
    {
        // on vérifie que ce n'est pas un system allié 
        if(owner != Player.getPlayer_id()){
            
            // le systeme apparteint maintenant au joueur 
            owner = PLayer.getPlayer_id();
            Player.addStellarSystem(StellarTarget);
            //enlever le systeme à l'autre joueur 
            cout << "le systeme apparteint maintenant au joueur"<< endl;
            // on détruit le vaisseau
            Player.destroyShip(ShipTarget);
            cout << "le vaisseau est détruit" << endl;
            
        }
        else
        {
            cout << "Vous ne pouvez pas colonizer un system qui vous appartient deja" << endl;
        }
    }
    else
    {
        cout << "Vous devez avoir tous vos points de mvt pour colonizer un system" << endl;
    }*/
}
Json::Value ColonizeCommand::serialize ()
{
    Json::Value newCommand;
    newCommand["id"] = this-> commandID;
    return newCommand;
}