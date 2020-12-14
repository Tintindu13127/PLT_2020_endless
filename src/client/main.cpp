#include <iostream>
#include <string.h>
// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML()
{
    sf::Texture texture;
}
// Fin test SFML

#include <state.h>
#include "render.h"


#include "client.h"
#include <iostream>
#include <unistd.h>
using namespace std;
using namespace state;
using namespace render;
using namespace client;


// Fin test SFML
#include "state.h"
using namespace state;
using namespace std;

void usage(char * argv0){
    cout << "Usage: " << argv0 << " COMMAND" << endl;
    cout << "\tCOMMAND := { ";
        cout << "hello" << " | ";
        cout << "state";
    cout << " }" << endl;
}

int main(int argc,char* argv[])
{
    if (argc == 1){
        usage(argv[0]);
        std::exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1],"hello") ==0 ){
        std::cout << "Woaw, quel code" << std::endl;
    }
	else if (strcmp(argv[1],"state") == 0){
		std::cout << "State" << std::endl;
	}
    else {
        std::cout << "Wrong command" << std::endl ;
    }
    return 0;

}
