#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <State.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    if (strcmp(argv[1],"hello")==0){
        std::cout << "Woaw, quel code" << std::endl;
    }
    else {
        std::cout << "Wrong command" << std::endl ;
    }
    return 0;

}
