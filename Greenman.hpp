#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"
class Greenman:public Player{
public:
	//takes two structs, two rectangles
	Greenman(SDL_Rect mover,SDL_Rect health, string face){
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
		Playerstates* leftface= new Playerstates{{829,153,63,116} , {829,153,63,116} , {707,151,51,118},  {768,152,51,117},    {510,584,104,107},    {696,446,99,108},{70,2305,79,117}};
		Playerstates* rightface= new Playerstates{{21,153,63,116},  {21,153,63,116},   {216,150,50,119},  {341,151,55,118} , {299,584,104,107}, {118,446,99,108},{358,2432,101,101}};
		string leftfaceimage="playerimg/greenmanleft.png";
		string rightfaceimage="playerimg/greenmanright.png";
};


