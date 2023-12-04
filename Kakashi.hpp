#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"

class Kakashi:public Player{
public:
	//takes two structs, two rectangles
	Kakashi(SDL_Rect mover,SDL_Rect health, string face){
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
	Playerstates* leftface= new Playerstates{{1487,138,50,83},   {1487,138,50,83} , {1206,130,63,90},  {1391,133,60,88},   {1162,258,93,111}, {1384,421,68,89},  {1205,565,72,86}};
	Playerstates* rightface= new Playerstates{  {1,422,60,87},    {1,422,60,87},     {377,275,48,94},   {1,275,60,94} ,   {283,258,93,111},  {86,421,68,89},    {261,565,72,86}};
	string leftfaceimage="playerimg/kakashileft.png";
	string rightfaceimage="playerimg/kakashiright.png";
};

