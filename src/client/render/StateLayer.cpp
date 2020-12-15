#include "../render.h"
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <queue>


using namespace render;
using namespace std;
using namespace state;


StateLayer::StateLayer(state::State& myState, sf::RenderWindow& window):window(window),currentState(myState){
   

   

   unique_ptr<TileSet>ptr_mapTileset(new TileSet(MAPTILESET);
       
   tileSets.push_back(move(ptr_mapTileset));
   

}
StateLayer::~StateLayer(){};


void StateLayer::initSurface(state::State& myState){
    Surface map;
    map.loadTextures(myState,*tileSets[0],myState.getMap()[0].size(),myState.getMap().size());
    unique_ptr<Surface> ptr_map(new Surface(map));
        
    if(Surface.size()!=0){
		while(Surface.size()!=0){
			Surface.pop_back();
		}
	}
    Surface.push_back(move(ptr_map));
}

void StateLayer::draw(sf::RenderWindow &window)
{
    window.clear();
    // draw mapcells
    window.draw(*Surface[0]);
    for (auto& m: message)
        window.draw(m);
    window.display();
}
