#include <iostream>
#include <string.h>
#include "dia2code_files/Ressource.h"

int hello(int argc, char* argv[]){
    if (strcmp(argv[1],"hello")==0){
        std::cout << "Woaw, quel code" << std::endl;
    }
    else {
        std::cout << "Wrong command" << std::endl ;
    }
    return 0;
}

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