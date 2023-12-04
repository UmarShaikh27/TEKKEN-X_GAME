#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"

class Redman:public Player{
public:
	//takes two structs, two rectangles
	Redman(SDL_Rect mover,SDL_Rect health, string face){
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
		Playerstates* leftface= new Playerstates{{302,242,32,78},  {438,242,37,78} , {302,242,32,78}, {438,161,37,79},{280,480,69,79},     {351,161,54,80}, {156,569,38,79}};
		Playerstates* rightface= new Playerstates{ {15,242,37,78},    {15,242,37,78},    {85,242,54,78},   {157,161,37,79} , {141,480,69,79}, {218,9,62,67},{296,569,38,81}};
		string leftfaceimage="playerimg/redmanleft.png";
		string rightfaceimage="playerimg/redmanright.png";
};

