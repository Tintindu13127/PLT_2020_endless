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
      // a enlever


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

            if (curState.getCurAction() == MOVING){
                for (auto &charac : curState.getListCharacters(0)){
                    if (charac->getStatus() == SELECTED && charac->getMovementLeft() > 0){
                        
                        int tilePosX = curState.getMap()[i][j]->getPosition().getX();
                        int tilePosY = curState.getMap()[i][j]->getPosition().getY();
                        for (auto &allowedPos : charac->allowedMove(curState)){
                            if( allowedPos.getX()== tilePosX && allowedPos.getY()==tilePosY){
                                Color c = Color(30, 144, 255);
                                quad[0].color = c;
                                quad[1].color = c;
                                quad[2].color = c;
                                quad[3].color = c;

                            }

                        }

                    }
                }
                // for now need to change by for players
                // will change by a for on player
                for (auto &charac : curState.getListCharacters(1)){
                    if (charac->getStatus() == SELECTED && charac->getMovementLeft() > 0){
                        
                        int tilePosX = curState.getMap()[i][j]->getPosition().getX();
                        int tilePosY = curState.getMap()[i][j]->getPosition().getY();
                        for (auto &allowedPos : charac->allowedMove(curState)){
                            if( allowedPos.getX()== tilePosX && allowedPos.getY()==tilePosY){
                                Color c = Color(30, 144, 255);
                                quad[0].color = c;
                                quad[1].color = c;
                                quad[2].color = c;
                                quad[3].color = c;

                            }

                        }

                    }
                }
            }
            if (curState.getCurAction() == ATTACKING){
                for (auto &charac : curState.getListCharacters(0)){
                    if (charac->getStatus() == SELECTED ){
                        
                        int tilePosX = curState.getMap()[i][j]->getPosition().getX();
                        int tilePosY = curState.getMap()[i][j]->getPosition().getY();
                        for (auto &allowedAttackPos : charac->allowedAttackPos(curState)){
                            if( allowedAttackPos.getX()== tilePosX && allowedAttackPos.getY()==tilePosY){
                                Color c = sf::Color::Red;
                                quad[0].color = c;
                                quad[1].color = c;
                                quad[2].color = c;
                                quad[3].color = c;

                            }

                        }

                    }
                }
                for (auto &charac : curState.getListCharacters(1)){
                    if (charac->getStatus() == SELECTED ){
                        
                        int tilePosX = curState.getMap()[i][j]->getPosition().getX();
                        int tilePosY = curState.getMap()[i][j]->getPosition().getY();
                        for (auto &allowedAttackPos : charac->allowedAttackPos(curState)){
                            if( allowedAttackPos.getX()== tilePosX && allowedAttackPos.getY()==tilePosY){
                                Color c = sf::Color::Red;
                                quad[0].color = c;
                                quad[1].color = c;
                                quad[2].color = c;
                                quad[3].color = c;

                            }

                        }

                    }
                }
            }


            

        }
    }
    return true;
}

void  TextureArea::draw(sf::RenderTarget& target, sf::RenderStates curState) const {
    // Apply a transformation
    curState.transform *= getTransform();

    // Apply texture of the tileset
    curState.texture = &texture;

    // Draw the table with the vertex
    target.draw(quads, curState);
}


bool TextureArea::loadCharacters(state::State& curState, render::TileSet& textureTileSet,int mapCellWidth, int mapCellHeight){

    texture= textureTileSet.getTexture();
    int cellWidth= textureTileSet.getCellWidth();
    int cellHeight= textureTileSet.getCellHeight();
    int nbPlyers= curState.getListPlayers().size();
    int nbCharacters= curState.getListCharacters(0).size();
    // each Player has the same nb of Character
    int vertexArrayIndex=0;
    
    quads.setPrimitiveType(sf::Quads);
    
    
    
    // Screen display for now
    
    for(int j=0; j<nbPlyers;j++){        
        for(int i=0; i<nbCharacters; i++){
            
            if (curState.getListCharacters(j)[i]->getStatus() !=DEATH){
                
                int tileNumber = curState.getListCharacters(j)[i]->getTileCode();
                quads.resize(quads.getVertexCount() + 4); 
                sf::Vertex* quad = &quads[vertexArrayIndex * 4];  
                vertexArrayIndex ++;

                int tx = tileNumber % (texture.getSize().x / cellWidth);
                int ty = tileNumber / (texture.getSize().x / cellWidth);
               

                quad[0].position = sf::Vector2f(
                curState.getListCharacters(j)[i]->getPosition().getX() * mapCellWidth,
                curState.getListCharacters(j)[i]->getPosition().getY() * mapCellHeight);
                quad[1].position = sf::Vector2f(
                (curState.getListCharacters(j)[i]->getPosition().getX()+1) * mapCellWidth,
                curState.getListCharacters(j)[i]->getPosition().getY() * mapCellHeight);
                quad[2].position = sf::Vector2f(
                (curState.getListCharacters(j)[i]->getPosition().getX()+1) * mapCellWidth,
                (curState.getListCharacters(j)[i]->getPosition().getY()+1) * mapCellHeight);
                quad[3].position = sf::Vector2f(
                curState.getListCharacters(j)[i]->getPosition().getX() * mapCellWidth,
                (curState.getListCharacters(j)[i]->getPosition().getY()+1) * mapCellHeight);


                quad[0].texCoords = sf::Vector2f(tx * cellWidth, ty * cellHeight);
                quad[1].texCoords = sf::Vector2f((tx + 1) * cellWidth, ty * cellHeight);
                quad[2].texCoords = sf::Vector2f((tx + 1) * cellWidth, (ty + 1) * cellHeight);
                quad[3].texCoords = sf::Vector2f(tx * cellWidth, (ty + 1) * cellHeight);
                
                if( curState.getMode()=="PlayervsAI"){
                    Color color = (curState.getListCharacters(j)[i]->getPlayerID()==1)? Color(0,0,int(255-j*80)) : Color(255-j*80,0,0);
                    quad[0].color = color;
                    quad[1].color = color;
                    quad[2].color = color;
                    quad[3].color = color;
            
                    
                }
                

                
                          


            }

        }
    }

    return true;

}


bool TextureArea::loadCursor(state::State &state,render::TileSet& textureTIleset )
{
    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    texture= textureTIleset.getTexture();
    int cellWidth= textureTIleset.getCellWidth();
    int cellHeight= textureTIleset.getCellHeight();
    
    quads.setPrimitiveType(sf::Quads);
    quads.resize(state.getMap().size() * state.getMap()[0].size() * 4);

    int tileNumber = state.getCursor().getTileCode();

    // on en déduit sa position dans la texture du tileset
    int tx = tileNumber % (texture.getSize().x / cellWidth);
    int ty = tileNumber / (texture.getSize().x / cellWidth);

    // on récupère un pointeur vers le quad à définir dans le tableau de vertex
    sf::Vertex *quad = &quads[4];

    // on définit ses quatre coins
    quad[0].position = sf::Vector2f(state.getCursor().getPosition().getX() * cellWidth, state.getCursor().getPosition().getY() * cellHeight);
    quad[1].position = sf::Vector2f((state.getCursor().getPosition().getX() + 1) * cellWidth, state.getCursor().getPosition().getY() * cellHeight);
    quad[2].position = sf::Vector2f((state.getCursor().getPosition().getX() + 1) * cellWidth, (state.getCursor().getPosition().getY() + 1) * cellHeight);
    quad[3].position = sf::Vector2f(state.getCursor().getPosition().getX() * cellWidth, (state.getCursor().getPosition().getY() + 1) * cellHeight);

    // on définit ses quatre coordonnées de texture
    quad[0].texCoords = sf::Vector2f(tx * cellWidth, ty * cellHeight);
    quad[1].texCoords = sf::Vector2f((tx + 1) * cellWidth, ty * cellHeight);
    quad[2].texCoords = sf::Vector2f((tx + 1) * cellWidth, (ty + 1) * cellHeight);
    quad[3].texCoords = sf::Vector2f(tx * cellWidth, (ty + 1) * cellHeight);

    return true;
}
