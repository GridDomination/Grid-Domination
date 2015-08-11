#include "Events.hpp"

Events::Events(){
	cursor.x = MAP_SIZE/2;
	cursor.y = MAP_SIZE/2;
	tex.loadFromFile("Resources/Cursor.png"); 
	cursor_sprite.setTexture(tex);
	
}

void Events::Update(HandleValues &values){
	cursor_sprite.setPosition((int)cursor.x * 64, (int)cursor.y * 64);
	UpdateCursor(.17);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    	values.Change(0, sf::Vector2i((int)cursor.x, (int)cursor.y), 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    	values.Change(1, sf::Vector2i((int)cursor.x, (int)cursor.y), 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    	values.Change(1, sf::Vector2i((int)cursor.x, (int)cursor.y), 1);
    static bool key_released = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U) and key_released == true){
    		values.Change(2, sf::Vector2i((int)cursor.x, (int)cursor.y), 1);
    		key_released = false;
    }else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::U))
    	key_released = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    	values.Change(3, sf::Vector2i((int)cursor.x, (int)cursor.y), 0);
}

void Events::Draw(sf::RenderWindow &window){
	window.draw(cursor_sprite);
}

void Events::UpdateCursor(float speed){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		cursor.y -= speed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		cursor.x += speed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		cursor.y += speed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		cursor.x -= speed;
}
