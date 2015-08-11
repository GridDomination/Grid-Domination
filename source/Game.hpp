#include "Events.hpp"

class Game{
	private:
		Map map;
		HandleValues values;
		Events events;
		void HandleView(sf::View &view, sf::View &static_view, sf::RenderWindow &window);
		
		sf::Text money_text; sf::Text help_text;
		sf::Font font;
	public:
		Game();
		void Update(sf::RenderWindow &window, sf::View &view, sf::View &static_view);
};
