#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"
class Mintman:public Player{
public:
	//takes two structs, two rectangles
	Mintman(SDL_Rect mover,SDL_Rect health, string face){
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
		Playerstates* leftface= new Playerstates{ {87,16,54,81},{87,16,54,81} , {216,111,32,88},       {536,561,46,75},     {327,219,54,81},    {154,16,60,82}, {312,440,40,81}};
		Playerstates* rightface= new Playerstates{{442,16,54,81},{442,16,54,81},{335,111,32,88},{398,319,34,89} ,   {267,319,54,91},   {369,16,60,82},    {231,440,40,81}};
		string leftfaceimage="playerimg/mintmanleft.png";
		string rightfaceimage="playerimg/mintmanright.png";
};

