#include "../render.h"
#include <iostream>
#include <fstream>

using namespace render;
using namespace state;
using namespace std;
using namespace sf;

bool Surface::loadTextures(state::State& curState,render::TileSet& textureTileSet,int width, int height){
    
    texture= textureTileSet.getTexture();
    int cellWidth= textureTileSet.getCellWidth();
    int cellHeight= textureTileSet.getCellHeight();
    
    
    quads.setPrimitiveType(sf::Quads);
    quads.resize(width*height*4); // Screen display for now
    int vertexArrayIndex=0;
     


    std::vector<std::vector<std::unique_ptr<MapCell>>> &map= curState.getMap();


       for (unsigned int i = 0; i < map.size(); ++i)
    {
        for (unsigned int j = 0; j < map[0].size(); j++){

            int tileNumber = map[i][j]->getTileCode();

            int tx= tileNumber%(texture.getSize().x/ cellWidth);
            int ty= tileNumber/(texture.getSize().x/ cellHeight );
            sf::Vertex* quad = &quads[vertexArrayIndex*4];
            vertexArrayIndex++;
            quad[0].position = sf::Vector2f(j*cellWidth, i*cellHeight);
            quad[1].position = sf::Vector2f((j+1)*cellWidth, i*cellHeight);
	        quad[2].position = sf::Vector2f((j+1)*cellWidth, (i+1)*cellHeight);
	        quad[3].position = sf::Vector2f(j*cellWidth, (i+1)*cellHeight);
            
            quad[0].texCoords = sf::Vector2f(tx * cellWidth, ty * cellHeight);
			quad[1].texCoords = sf::Vector2f((tx + 1) * cellWidth, ty * cellHeight);
			quad[2].texCoords = sf::Vector2f((tx + 1) * cellWidth, (ty + 1) * cellHeight);
			quad[3].texCoords = sf::Vector2f(tx * cellWidth, (ty + 1) * cellHeight);
         

        }
    }
    return true;
}

void  Surface::draw(sf::RenderTarget& target, sf::RenderStates curState) const {
    // Apply a transformation
    curState.transform *= getTransform();

    // Apply texture of the tileset
    curState.texture = &texture;

    // Draw the table with the vertex
    target.draw(quads, curState);
}


bool Surface::loadShip(state::State& curState, render::TileSet& textureTileSet,int mapCellWidth, int mapCellHeight){

    texture= textureTileSet.getTexture();
    int cellWidth= textureTileSet.getCellWidth();
    int cellHeight= textureTileSet.getCellHeight();
    int nbPlyers= curState.getListPlayers().size();
    int nbCharacters= curState.getListCharacters(0).size();
    // each Player has the same nb of Character
    int vertexArrayIndex=0;
    
    quads.setPrimitiveType(sf::Quads);
    
    
    return true;

}


