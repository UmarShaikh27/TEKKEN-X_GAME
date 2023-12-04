#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"

class Graywoman:public Player{
public:
	//takes two structs, two rectangles
	Graywoman(SDL_Rect mover,SDL_Rect health, string face){
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
		Playerstates* leftface= new Playerstates{{760,25,48,108},{760,25,48,108} , {707,22,46,108}, {650,22,47,108},{422,596,71,141},{660,255,83,102},{139,644,73,112}};
		Playerstates* rightface= new Playerstates{{25,25,48,108}, {25,25,48,108},{80,22,46,108},{136,22,47,108} , {727,267,84,113}, {90,255,83,102},{714,648,89,90}};
		string leftfaceimage="playerimg/graywomanleft.png";
		string rightfaceimage="playerimg/graywomanright.png";
};