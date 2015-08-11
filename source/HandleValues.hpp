#include "Hardware.hpp"
#define MAP_SIZE 16

class HandleValues{
	private:
		int money; float money_add;
		int owner[MAP_SIZE][MAP_SIZE];
		int building[MAP_SIZE][MAP_SIZE]; int buildcount;
		int units[MAP_SIZE][MAP_SIZE];
		int resourcecount; int bankcount;
	public: 
		HandleValues();
		int Money();
		int BuildingPrice(); int MoneyCap();
		int Value(sf::Vector2i pos, int num);
		void Change(int var, sf::Vector2i pos, int val);
		void Update();
};
