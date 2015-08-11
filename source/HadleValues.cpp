#include "HandleValues.hpp"

HandleValues::HandleValues(){
	for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
        	owner[i][j] = -1;
        	building[i][j] = -1;
        	units[i][j] = 0;
        }
    }
    owner[MAP_SIZE/2][MAP_SIZE/2] = 0;
    owner[4][4] = 1; owner[5][4] = 1; owner[6][4] = 1; units[5][4] = 15; 
    money = 100;
    buildcount = 0; resourcecount = 0; bankcount = 1;
    srand(time(NULL));
}

void HandleValues::Update(){
	static float money_add = 0;
	static float clock = 0;
	clock += .01;
	money_add += .01 + .01 * resourcecount;
	if(money_add > 1){
		money_add = 0;
		money++;
	}
	//if(money > bankcount * 100)
		money = bankcount * 100;
	if(clock > 1){
	clock = 0;
	for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
        	if(owner[i][j] > -1 and owner[i + 1][j] != owner[i][j] and owner[i + 1][j] > -1){
        		if(rand() % (units[i][j] + 2) > rand() % (units[i + 1][j] + 2)){
        			owner[i + 1][j] = owner[i][j]; units[i + 1][j] = units[i + 1][j]/2;}
        	}
        	if(owner[i][j] > -1 and owner[i][j + 1] != owner[i][j] and owner[i][j + 1] > -1){
        		if(rand() % (units[i][j] + 2) > rand() % (units[i][j + 1] + 2)){
        			owner[i][j + 1] = owner[i][j]; units[i][j + 1] = units[i][j + 1]/2;}
        	}
        	if(owner[i][j] > -1 and owner[i - 1][j] != owner[i][j] and owner[i - 1][j] > -1){
        		if(rand() % (units[i][j] + 2) > rand() % (units[i - 1][j] + 2)){
        			owner[i - 1][j] = owner[i][j]; units[i - 1][j] = units[i - 1][j]/2;}
        	}
        	if(owner[i][j] > -1 and owner[i][j - 1] != owner[i][j] and owner[i][j - 1] > -1){
        		if(rand() % (units[i][j] + 2) > rand() % (units[i][j - 1] + 2)){
        			owner[i][j - 1] = owner[i][j]; units[i][j - 1] = units[i][j - 1]/2;}
        	}
        }
    }}	
}

int HandleValues::Money(){
	return money;
}

int HandleValues::BuildingPrice(){
	return (buildcount * 3)*(buildcount + 1);
}

int HandleValues::MoneyCap(){
	return bankcount * 100;
}

void HandleValues::Change(int var, sf::Vector2i pos, int val){
	switch(var){
		case 0:
			if(owner[pos.x][pos.y] != -1 or (owner[pos.x - 1][pos.y] != 0 and owner[pos.x][pos.y - 1] != 0 and owner[pos.x + 1][pos.y] != 0 and  owner[pos.x][pos.y + 1] != 0) or money < 10)
				break;
			money -= 10;
			owner[pos.x][pos.y] = val;
			break;
		case 1:
			if(owner[pos.x][pos.y] != 0 or building[pos.x][pos.y] != -1 or money < (buildcount * 3)*(buildcount + 1))
				break;
			money -= (buildcount * 3)*(buildcount + 1);
			building[pos.x][pos.y] = val;
			buildcount ++;
			if(val == 0)
				resourcecount++;
			if(val == 1)
				bankcount++;
			
			break;
		case 2:
			if(owner[pos.x][pos.y] != 0 or building[pos.x][pos.y] != -1 or money < 10)
				break;
			money -= 10;
			units[pos.x][pos.y] += val;
			break;
		case 3:
			if(owner[pos.x][pos.y] == 0){
				money += units[pos.x][pos.y]*5 + 5;
				owner[pos.x][pos.y] = -1;
				building[pos.x][pos.y] = -1;
				units[pos.x][pos.y] = 0;
				
			}
			break;
	}
}

int HandleValues::Value(sf::Vector2i pos, int num){
	int val[3];
	val[0] = owner[pos.x][pos.y];
	val[1] = building[pos.x][pos.y];
	val[2] = units[pos.x][pos.y];
	return val[num];
}
