#pragma once
#include "Player.hpp"
#include "Playerstates.hpp"

/**
 *  Kakashi character class implementing the Player interface
 * 
 * Represents the Kakashi fighter character with:
 * - Custom sprite animations for attacks
 * - Specific hit boxes and movement rectangles
 * - Character-specific asset paths
 * - Unique animation frame coordinates
 */
class Kakashi : public Player {
public:
    /**
     *  Constructs a new Kakashi fighter
     * @param mover Rectangle defining character's position and size
     * @param health Rectangle defining health bar position and size
     * @param face Direction the character is facing ("left" or "right")
     */
    Kakashi(SDL_Rect mover, SDL_Rect health, string face) {
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

