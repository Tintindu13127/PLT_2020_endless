#include "StateLayer.h"
#include <iostream>
#include <fstream>
#include <iomanip>
// #include <SFML/Graphics.hpp>
using namespace std;
using namespace render;
using namespace state;


StateLayer:: StateLayer (state::Position const& position)
	
	
	{
		this->map.load("res/spaceship_1_preview.png",sf::Vector2u(16,16));
		this->window = new sf::RenderWindow(sf::VideoMode(720,720), "One Upon A Wei",sf::Style::Close);
		this->view = new  sf::View(sf::Vector2f(0.f, 10.f), sf::Vector2f(360.f, 360.f));
		

		
	}


void StateLayer :: update(){
	this->window->clear();
	
	window->setView(*view);

	this->window->draw(map);
	
	
	this->window->display();
}

void StateLayer :: end(){
	this->window->close();
}

