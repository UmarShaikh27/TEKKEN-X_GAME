#pragma once
#include <SDL.h>
#include "Playerstates.hpp"
#include <iostream>
using namespace std;

class Player{

public:
    // SDL_Rect srcRect,moverRect,walkOne,walkTwo,walkThree,kickRect,punchRect,hitRect,healthrect;
    SDL_Rect moverRect,healthrect;
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
    void changeState(){
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
    void punchAttack(Player* playerTwo){
        Data->srcRect = Data->punchRect;
        if(abs(moverRect.x-playerTwo->moverRect.x) < 170){
            playerTwo->getPunched();
        }
    }

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
    


    void getPunched(){
        Data->srcRect=Data->hitRect;
        this->healthrect.w-=5;

    }
    void getKicked(){
        Data->srcRect=Data->hitRect;
        this->healthrect.w-=10;
    }
    // virtual void specialAttack();
    // virtual void getAttacked();
private:
    Playerstates* leftface,rightface;
};