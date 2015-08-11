#include "Game.hpp"

Game::Game(){
	font.loadFromFile("Resources/arial.ttf");
	money_text.setFont(font); money_text.setCharacterSize(42); money_text.setColor(sf::Color::Black);
	help_text.setFont(font); help_text.setCharacterSize(18); help_text.setColor(sf::Color::Black); help_text.setPosition(sf::Vector2f(0, 50));
}

void Game::Update(sf::RenderWindow &window, sf::View &view, sf::View &static_view){
    window.setView(view);
	events.Update(values);
	values.Update();
	map.Draw(values, window);
	events.Draw(window);
	HandleView(view, static_view, window);
}

void Game::HandleView(sf::View &view, sf::View &static_view, sf::RenderWindow &window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		view.move(0, -16);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		view.move(-16, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		view.move(0, 16);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		view.move(16, 0);
		
	window.setView(static_view);
	money_text.setString("Money: " + SSTR(values.Money()));
    window.draw(money_text);
    static bool help_toggled = true;
    static bool key_released = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H) and key_released == true){
    		help_toggled = !help_toggled;
    		key_released = false;
    }else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    	key_released = true;
    if(help_toggled){
    	help_text.setString("building price: " + SSTR(values.BuildingPrice()) + "\nclaim & upgrade price = 10\nmoney cap = " + SSTR(values.MoneyCap()) + "\n\nc = claim\nr = build resource\nb = build bank\nu = improve\np = sell for 10\n\ntoggle help = h");
    	window.draw(help_text);
    }
}
