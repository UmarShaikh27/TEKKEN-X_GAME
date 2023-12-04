#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"

class Blueman:public Player{
public:
	//takes two structs, two rectangles
	Blueman(SDL_Rect mover,SDL_Rect health, string face){
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
    Playerstates* leftface = new Playerstates{{412,173,61,108},{163,339,109,92},{331,341,63,90},{448,345,101,85},{478,167,55,111},{753,167,90,113},{20,338,67,94}};
    Playerstates* rightface = new Playerstates{{592,339,109,92},{592,339,109,92},  {470,341,63,90}, {315,345,101,85} ,{331,167,55,111},{297,491,82,84},{50,483,63,93}};
	string leftfaceimage="playerimg/bluemanleft.png";
	string rightfaceimage="playerimg/bluemanright.png";
};
