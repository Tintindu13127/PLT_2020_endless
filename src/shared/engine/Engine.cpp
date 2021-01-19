#include "Engine.h"
#include <iostream>
#include <unistd.h>


using namespace state;
using namespace engine;
using namespace std;

Engine::Engine(){}

Engine::~Engine(){}

void Engine::addCommand(std::unique_ptr<Command> ptr_cmd)
{
    Json::Value newCommand = ptr_cmd->serialize();
    record["CommandArray"][record["Size"].asUInt()] = newCommand;
    record["Size"] = record ["Size"].asUInt() +1 ;
}



//getters

state::State& Engine::getState(){
	return this->currentState;
}

Json::Value Engine::getRecord(){
	return this->record;
}

std::map<int, std::unique_ptr<Command>>& Engine::getCurrentCommands(){
	return this->currentCommands;
}

//setters

void Engine::setState(state::State& currentState) {
	this-> currentState = currentState;
}

void Engine::setRecord(Json::Value record){
	this->record= record ;
}