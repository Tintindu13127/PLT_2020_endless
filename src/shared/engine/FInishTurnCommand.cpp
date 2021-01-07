#include "FinishTurnCommand.h"
#include <iostream>
#include <unistd.h> 

using namespace engine;
using namespace state;
using namespace std;

FinishTurnCommand::FinishTurnCommand() { this->commandID = FINISH_TURN;}

void FinishTurnCommand::execute(state::State& state)
{
    //ajouter les ressources produitent au player

    // actuliser la production 

    //reset le mouvement et attack 
    state.setTurn(state.getTurn()+1)
}

Json::Value FinishTurnCommand::serialize()
{
    Json::Value newCommand;
    newCommand["id"] = this-> commandID;
    return newCommand;
}