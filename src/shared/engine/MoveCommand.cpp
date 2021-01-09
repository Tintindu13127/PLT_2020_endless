#include "MoveCommand.h"
#include <iostream>
#include <unistd.h> 

using namespace engine;
using namespace state;
using namespace std;

MoveCommand::MoveCommand(state::Ship& refShipTarget, state::Position& refPositionTarget) : ShipTarget(refShipTarget), PositionTarget(refPositionTarget) 
{
    this->commandID = MOVE;
}

void MoveCommand::execute(state::State& state)
{
    cout << "move" <<endl;
    bool allowed = false;
    if(ShipTarget.getMoveShip_map() != null)
    {
        for (auto &pos: ShipTarget.getMoveShip_map())
        {
            // On vérifie si la position se trouve dans les positions possibles et qu'il n'y a pas d'allié sur la case
            /*if (pos.equals(targetedPos) && )         
                {
                    //on déplace le vaisseaux

                    //on actualise la carte des mouvements 
                    ShipTarget.add_MoveShipMap();
                    
                    // la case actuelle est occupé par un allié 

                    allowed = true;
                    break;
                    cout << "le vaisseau a été bougé" << endl;
                }
            */
            
        }
        if(!allowed)
        {
            cout << "le vaisseau ne peut se déplacer sur cette case" << endl;
        }
    }
    cout << "le vaisseau a utilisé tous ses points de mouvement" << endl;

    else cout << "no movement left" << endl;
}

J
son::Value MoveCommand::serialize()
{
    Json::Value newCommand;
    newCommand["id"] = this-> commandID;
    return newCommand;
}