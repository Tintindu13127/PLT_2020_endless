#include "Surface.h"
#include "../render.h"
#include "state.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace render;

bool Surface :: load(const std::string& tileset, sf::Vector2u tileSize){

  
    // load the tileset texture
    if (!this->m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    this->m_vertices.setPrimitiveType(sf::Quads);
    this->m_vertices.resize(tiles.size() * tiles[0].size()*4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < tiles.size(); ++i)
        for (unsigned int j = 0; j < tiles[i].size(); ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i][j];

            // find its position in the tileset texture
            int tu = tileNumber %(m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber /(m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * tiles.size()) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

std::vector<std::vector <int > > Surface :: load_map(std::string fileName){

    std::ifstream infile(fileName);
    std::vector<std::vector <int> > map;
    std::vector<int> lineVector;
    std::string sum="";

    for(std::string line; getline( infile, line );){
        for(char elem : line){
            if (elem == ',' or elem == ' '){
                lineVector.push_back(std::stoi (sum));
                sum = "";
            }else{
                sum+=elem;
            }
        }
        sum = "";
        map.push_back(lineVector);
        lineVector.clear();
    }
    return map;
}


void Surface::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  // apply the transform
  states.transform *= getTransform();

  // apply the tileset texture
  states.texture = &m_tileset;

  // draw the vertex array
  target.draw(m_vertices, states);
}
