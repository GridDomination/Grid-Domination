#include "Map.hpp"

Map::Map(){	
	owner_tex[0].loadFromFile("Resources/Blue.png");
	owner_tex[1].loadFromFile("Resources/Red.png");
	building_tex[0].loadFromFile("Resources/Resource.png");
	building_tex[1].loadFromFile("Resources/Bank.png");
	font.loadFromFile("Resources/arial.ttf");
	for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
        	owner_sprite[i][j].setTexture(owner_tex[0]);
        	owner_sprite[i][j].setPosition(sf::Vector2f((float)(i)*64, (float)(j)*64));
        	building_sprite[i][j].setTexture(owner_tex[0]);
        	building_sprite[i][j].setPosition(sf::Vector2f((float)(i)*64, (float)(j)*64));
        	units_text[i][j].setFont(font); units_text[i][j].setCharacterSize(24); units_text[i][j].setColor(sf::Color::Black);
        	units_text[i][j].setPosition(sf::Vector2f((float)(i)*64, (float)(j)*64));
        }
    }
}

void Map::Draw(HandleValues values, sf::RenderWindow &window){
	for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
        	if(values.Value(sf::Vector2i(i, j), 0) >= 0){
        		owner_sprite[i][j].setTexture(owner_tex[values.Value(sf::Vector2i(i, j), 0)]);
        		
        		window.draw(owner_sprite[i][j]);
        	}
        	if(values.Value(sf::Vector2i(i, j), 1) >= 0){
        		building_sprite[i][j].setTexture(building_tex[values.Value(sf::Vector2i(i, j), 1)]);
        		
        		window.draw(building_sprite[i][j]);
        	}
        	if(values.Value(sf::Vector2i(i, j), 2) > 0){
        		units_text[i][j].setString(SSTR(values.Value(sf::Vector2i(i, j), 2)));
        		
        		window.draw(units_text[i][j]);
        	}
        }
    }
}

        	//if(mapBlock[i][j].getPosition().x < SCREEN_WIDTH + 32 && mapBlock[i][j].getPosition().x > -32 && mapBlock[i][j].getPosition().y < SCREEN_HEIGHT + 32 && mapBlock[i][j].getPosition().y > -32)
