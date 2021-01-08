#include "Command.h"
#include <iostream>
#include <unistd.h>

using namespace engine;


//setters

void Command::setCommandID(CommandID commandID) { this->commandID = commandID;}

void Command::setCurrentPlayer(state::Player currentPlayer) {this-> currentPlayer = currentPlayer;}

//getters

CommandID Command::getCommandID(){return this->commandID;}

state::Player Command::getCurrentPlayer(){return this->currentPlayer;}

