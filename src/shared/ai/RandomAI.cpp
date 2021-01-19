#include "RandomAI.h"
#include "engine.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>



using namespace ai;
using namespace std;
using namespace state;
using namespace engine;


void RandomAI::run(engine::Engine& myEngine){

    /*Player player = myEngine.getState().player_turn();
    std::vector<Ship> list_ship = player.getList_ship();
    
    for(unsigned int i = 0; i < list_ship.size(); i++)
    {
        int random = rand() % 100 + 1 ;
        Ship ship = list_ship[i];
        if(random < 30)
        {
            // déplacement 
            std::vector<SpaceCell> moveShip_map = ship.getMoveShip_map();
            int randomMov = rand() % moveShip_map.size();
            unique_ptr<engine::Command> ptr_mv(new MoveCommand(ship,moveShip_map[randomMov]));
            myEngine.addCommand(move(ptr_mv));
        }
        if(random > 29 && random < 70)
        {
            //attaque
            unique_ptr<engine::Command> ptr_atk(new AttackCommand(ship,ship.getPosition()));
            myEngine.addCommand(move(ptr_atk));
        }
        else 
        {
            //colonize

            unique_ptr<engine::Command> ptr_col(new ColonizeCommand(ship,ship.getPosition()));
            myEngine.addCommand(move(ptr_col));
        }
    }
    unique_ptr<Command> ptr_fin(new FinishTurnCommmand());
    myEngine.addCommand(move(ptr_fin));*/
}
