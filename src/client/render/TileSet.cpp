#include <string>
#include "../render.h"

using namespace render;

// Constructor

TileSet::TileSet(TileSetID ID,std::string mode){
    id = ID;
    
    switch(id){
        case MAPTILESET:
            cellWidth=32;
            cellHeight=32;         
            resFile="res/purple.png";
            
            break;
    }

    textureTileSet.loadFromFile(resFile);
}

// Getters

int const TileSet::getCellWidth(){
    return cellWidth;
}

int const TileSet::getCellHeight(){
    return cellHeight;
}

TileSetID TileSet::getTileSetID(){
    return id;
}

sf::Texture& TileSet::getTexture(){
    return textureTileSet;
}
