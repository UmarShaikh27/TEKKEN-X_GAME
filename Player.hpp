#pragma once
#include "SDL.h"
#include "Playerstates.hpp"
#include <iostream>
using namespace std;

/**
 * @class Player
 *  Base class for all playable characters in the game
 * 
 * This abstract class defines the interface and common functionality
 * for all player characters. It handles movement, attacks, health,
 * and character states using SDL rectangles for collision and rendering.
 */
class Player {
public:
    // Rectangle for character position and collision on screen
    SDL_Rect moverRect;
    // Rectangle for health bar rendering
    SDL_Rect healthrect;
    Playerstates* Data;
    Player() = default;
    string leftfaceimage="playerimg/redmanright.png";
	string rightfaceimage="playerimg/redmanright.png";
	bool flipstate=true;
    virtual void flip() = 0;
    virtual string getterleft(){};
    virtual string getterright(){};
    
    // Player(SDL_Rect srcRect, SDL_Rect moverRect,SDL_Rect walkOne,SDL_Rect walkTwo,SDL_Rect walkThree,SDL_Rect kickRect,SDL_Rect punchRect,SDL_Rect hitRect,SDL_Rect healthRect):
    //                                                                                                                 srcRect(srcRect),
    //                                                                                                                 moverRect(moverRect),
    //                                                                                                                 walkOne(walkOne),
    //                                                                                                                 walkTwo(walkTwo),
    //                                                                                                                 walkThree(walkThree),
    //                                                                                                                 kickRect(kickRect),
    //                                                                                                                 punchRect(punchRect),
    //                                                                                                                 hitRect(hitRect),
    //                                                                                                                 healthrect(healthRect)                                                                                                                 
    //                                                                                                                 {}
   
    // virtual void flip() = 0;
    virtual void deletePlayer() = 0;                 
    /**
     *  Updates the character's walking animation state
     * 
     * Cycles through three walking animation frames (walkOne, walkTwo, walkThree)
     * to create a smooth walking animation when the character moves.
     */
    void changeState() {
        if(Data->srcRect.x == Data->walkOne.x && Data->srcRect.y == Data->walkOne.y){
            Data->srcRect = Data->walkTwo;
        }
        else if(Data->srcRect.x == Data->walkTwo.x && Data->srcRect.y == Data->walkTwo.y){
            Data->srcRect = Data->walkThree;
        }
        else{
            Data->srcRect = Data->walkOne;
        }
    }
    /**
     *  Executes a punch attack against another player
     * @param playerTwo Pointer to the player being attacked
     * 
     * Changes character sprite to punch animation and checks if the
     * target player is within attack range (170 pixels). If in range,
     * applies punch damage to the target.
     */
    void punchAttack(Player* playerTwo){
        Data->srcRect = Data->punchRect;
        if(abs(moverRect.x-playerTwo->moverRect.x) < 170){
            playerTwo->getPunched();
        }
    }

    /**
     *  Executes a kick attack against another player
     * @param playerTwo Pointer to the player being attacked
     * 
     * Changes character sprite to kick animation and checks if the
     * target player is within attack range (170 pixels). If in range,
     * applies kick damage (higher than punch) to the target.
     */
    void kickattack(Player* playerTwo)
    {
        SDL_Rect temp  =  Data->srcRect;
        Data->srcRect = Data->kickRect;
        
        if(abs(moverRect.x-playerTwo->moverRect.x) < 170){
            playerTwo->getKicked();
        }
    }

    void unPunch(Player* playerTwo){
        if(Data->srcRect.x == Data->punchRect.x && Data->srcRect.y == Data->punchRect.y){    
            Data->srcRect = Data->walkOne;
            playerTwo->Data->srcRect = playerTwo->Data->walkOne;
        }
        
    }

    void unkick(Player* playerTwo)
    {
        if(Data->srcRect.x == Data->kickRect.x && Data->srcRect.y == Data->kickRect.y){    
            Data->srcRect = Data->walkOne;
            playerTwo->Data->srcRect = playerTwo->Data->walkOne;
        }
    }
    


    /**
     *  Handles the player receiving a punch attack
     * 
     * Changes the character sprite to hit animation and
     * reduces health by 5 points (displayed in health bar)
     */
    void getPunched(){
        Data->srcRect=Data->hitRect;
        this->healthrect.w-=5;
    }

    /**
     *  Handles the player receiving a kick attack
     * 
     * Changes the character sprite to hit animation and
     * reduces health by 10 points (displayed in health bar)
     * Kick does more damage than punch.
     */
    void getKicked(){
        Data->srcRect=Data->hitRect;
        this->healthrect.w-=10;
    }
    // virtual void specialAttack();
    // virtual void getAttacked();
private:
    Playerstates* leftface,rightface;
};