#include "HandleValues.hpp"
#include <string>

#define OWN_COUNT 2										//create some enums
#define BUILD_COUNT 2
class Map{
	private:
		sf::Texture owner_tex[OWN_COUNT];
		sf::Texture building_tex[BUILD_COUNT];
		
		sf::Font font;
	public:
		Map();
		void Draw(HandleValues values, sf::RenderWindow &window);
		
		sf::Sprite owner_sprite[MAP_SIZE][MAP_SIZE];			//Globals, use sparingly
		sf::Sprite building_sprite[MAP_SIZE][MAP_SIZE];			//Currently used in HandleValues.cpp
		sf::Text units_text[MAP_SIZE][MAP_SIZE];	
}; 
