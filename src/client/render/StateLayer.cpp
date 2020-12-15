#include "../render.h"
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <queue>


using namespace render;
using namespace std;
using namespace state;


StateLayer::StateLayer(state::State& myState, sf::RenderWindow& window,std::string mode):window(window),currentState(myState){
   

   //TileSet tileSetMap(MAPTILESET,mode);
   unique_ptr<TileSet>ptr_mapTileset(new TileSet(MAPTILESET,mode));
       
   tileSets.push_back(move(ptr_mapTileset));
   

}
StateLayer::~StateLayer(){};


void StateLayer::initTextureArea(state::State& myState){
    TextureArea map;
    map.loadTextures(myState,*tileSets[0],myState.getMap()[0].size(),myState.getMap().size());
    unique_ptr<TextureArea> ptr_map(new TextureArea(map));
        
    if(textureAreas.size()!=0){
		while(textureAreas.size()!=0){
			textureAreas.pop_back();
		}
	}
    textureAreas.push_back(move(ptr_map));
}

void StateLayer::draw(sf::RenderWindow &window)
{
    window.clear();
    // draw mapcells
    window.draw(*textureAreas[0]);
    for (auto& m: message)
        window.draw(m);
    window.display();
}
