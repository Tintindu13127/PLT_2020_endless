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
    std::cout << "move" <<std::endl;
    bool allowed = false;
	Position ship_pos = ShipTarget.getPosition();
    if(ShipTarget.getMovement_left() != 0)
    {
        for (auto cell: ShipTarget.getMoveShip_map())
        {
            Position pos = cell.getPosition();
            // On vérifie si la position se trouve dans les positions possibles et qu'il n'y a pas d'allié sur la case
			if ( !(pos.IsPosEqual(PositionTarget)) && !(cell.isOccupiedbyAlly(state)) )         
                {                   
					//on déplace le vaisseaux et on actualise les PM left
					ShipTarget.setPosition(PositionTarget);
					ShipTarget.setMovement_left(ShipTarget.getMovement_left() - ship_pos.DistanceToTarget(PositionTarget));

                    //on actualise la carte des mouvements 
                    ShipTarget.add_MoveShipMap(state);
                    

                    allowed = true;
                    break;
                    std::cout << "le vaisseau a été bougé" << std::endl;
                }
            
            
        }
        if(!allowed)
        {
            std::cout << "le vaisseau ne peut se déplacer sur cette case" << std::endl;
        }
    }
    std::cout << "le vaisseau a utilisé tous ses points de mouvement" << std::endl;

}

Json::Value MoveCommand::serialize()
{
    Json::Value newCommand;
    newCommand["id"] = this-> commandID;
    return newCommand;
}