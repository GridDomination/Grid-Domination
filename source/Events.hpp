#include "Hardware.hpp"
#include "Map.hpp"

class Events{
	private:
		sf::Vector2f cursor;
		sf::Texture tex; 
		sf::Sprite cursor_sprite;
	public:
		Events();
		void Update(HandleValues &values);
		void UpdateCursor(float speed);
		void Draw(sf::RenderWindow &window);
};
