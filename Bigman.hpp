#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"

class Bigman:public Player{
public:
	//takes two structs, two rectangles
	Bigman(SDL_Rect mover,SDL_Rect health, string face){
		moverRect = mover;
		healthrect = health;
		Data = (face=="right")? rightface : leftface;
	}

	void flip(){
		Data = (Data==leftface)? rightface : leftface;
		flipstate = !flipstate;
	}
	bool flipstate=true;
	string getterleft()
	{
		return leftfaceimage;
	};
	string getterright()
	{
		return rightfaceimage;
	};
	void deletePlayer(){
		delete leftface;
		delete rightface;
		leftface = nullptr;
		rightface = nullptr;
	}
private:
		Playerstates* leftface= new Playerstates{{429,127,64,106},{429,127,64,106} , {352,128 ,64, 108}, {271,131,64,107},{252,259,74,113},{216,529,114,92},{336,636,61,104}};
		Playerstates* rightface= new Playerstates{{249,131,66,106},{249,131,66,106} , {330,129,64,108}, {7,127,64,106},{174,259,74,113},{170,529,114,92},{103,636,61,104}};
		string leftfaceimage="playerimg/bigmanleft.png";
		string rightfaceimage="playerimg/bigmanright.png";
};