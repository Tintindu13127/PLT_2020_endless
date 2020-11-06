#include <iostream>
#include <string.h>
#include "dia2code_files/Ressource.h"


namespace state{

void Ressource::setTech(int tech){
    this->technologie=tech;
}

void Ressource::setBrume(int brume){
    this->brume=brume;
}

void Ressource::setScience(int science){
    this->science=science;
}

void Ressource::setFood(int food){
    this->food=food;
}

}