#pragma once
#include <SDL.h>
// #include <SDL_ttf.h>
#include <SDL_image.h>
// #include <SDL_mixer.h>
// #include <SDL_mixer.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Player.hpp"
#include "Bluewoman.hpp"
#include "Graywoman.hpp"
#include "Kakashi.hpp"
#include "Blueman.hpp"
#include "Redman.hpp"
#include "Mintman.hpp"
#include "Greenman.hpp"
#include "Bigman.hpp"
#include "Playerstates.hpp"
#include "Timer.hpp"

// #include "startup.hpp"
// #include "Warrior.hpp"
// #include "Soldier.hpp"

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;
   

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;
   

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    //global reference to png image sheets
    SDL_Texture* assetsOne=NULL;
    SDL_Texture* assetsTwo=NULL;
    SDL_Texture* whitetexture=NULL;
    SDL_Texture* greentexture=NULL;
    SDL_Rect greenSRCrect={0,0,396,497};
	SDL_Rect whiteSRCrect={0,0,396,497};
	SDL_Rect greenMOVErect1={10,10,300,30};
    SDL_Rect greenMOVErect2={685,10,300,30};
	SDL_Rect whiteMOVErect1={7,7,306,36};
    SDL_Rect whiteMOVErect2={682,7,306,36};
    // TTF_Font* font;

    

public:
    bool init();
    bool loadMedia();
    void drawBg();    
    void close();
    void endGame(Player* playerOne,Player* playerTwo);
    void setAssetsOne(string str);
    void setAssetsTwo(string str);
    SDL_Texture* loadTexture( std::string path );
    void changeBg(std::string str);
    void run();
};

class startup{
public:
    startup(Game* newGame){
        theGame = newGame;
    }
    void drawGrounds(){
        theGame->changeBg("choosebackground.jpeg");
        SDL_Event e;
        bool quit = false;
        while(!quit){
            while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                    theGame->close();
                }
                if(e.type == SDL_KEYDOWN) {
                    SDL_Keycode symbol = e.key.keysym.sym;
                    if(symbol == SDLK_1){
                        theGame->changeBg("background1.png");
                        quit=true;
                    }
                    else if(symbol == SDLK_2){
                        theGame->changeBg("background2.png");
                        quit=true;
                    }
                    else if(symbol == SDLK_3){
                        theGame->changeBg("background3.jpeg");
                        quit=true;
                    }
                    else{
                        cout<<"Invalid key"<<endl;
                    }
                }
            }
            theGame->drawBg();
            
            SDL_Delay(50);
        }
        cout<<"exiting the loop"<<endl;
    }
    void restart(){
        theGame->changeBg("restartscreen.jpeg");
        cout<<"R to restart, q to quit"<<endl;
        // const Uint8* keyState = SDL_GetKeyboardState(NULL);
        SDL_Event e;
        bool quit = false;
        while(!quit){
            while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                    theGame->close();

                }
                SDL_Keycode symbol = e.key.keysym.sym;
                if(symbol == SDLK_r){
                    theGame->run();
                    quit = true;
                }
                else if(symbol == SDLK_q){
                    quit = true;
                    theGame->close();
                }
            }
            theGame->drawBg();
            
            SDL_Delay(50);
        }
        cout<<"exiting the loop"<<endl;
    }
    Player* choosePlayers(int playerNum){
        static int state = 1;
        if(playerNum==1){
            theGame->changeBg("chooseplayerone.jpeg");
        }else{
            theGame->changeBg("chooseplayertwo.jpeg");
        }
        const Uint8* keyState = SDL_GetKeyboardState(NULL);
        SDL_Event e;
        bool quit = false;
        SDL_Rect healthLeft = {10,10,300,30}, healthRight = {685,10,300,30};
        SDL_Rect moverLeft = {100,300,150,270} , moverRight = {800,300,150,270};
        
        while(!quit){
            while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                    theGame->close();
                }
                if(e.type == SDL_KEYDOWN) {
                    SDL_Keycode symbol = e.key.keysym.sym;
                    if(symbol == SDLK_1){
                        if(playerNum==1){
                            Player* player = new Bluewoman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/bluewomanright.png");
                            return player;
                        }else{
                            Player* player = new Bluewoman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/bluewomanleft.png");
                            return player;
                        }
                    }
                    else if(symbol == SDLK_2){
                        if(playerNum==1){
                            Player* player = new Graywoman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/graywomanright.png");
                            return player;
                        }else{
                            Player* player = new Graywoman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/graywomanleft.png");
                            return player;

                        }
                    }
                    else if(symbol == SDLK_3){
                        if(playerNum==1){
                            Player* player = new Kakashi(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/kakashiright.png");
                            return player;
                        }else{
                            Player* player = new Kakashi(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/kakashileft.png");
                            return player;
                        }
                    }
                    else if(symbol == SDLK_4){
                        if(playerNum==1){
                            Player* player = new Blueman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/bluemanright.png");
                            return player;
                        }else{
                            Player* player = new Blueman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/bluemanleft.png");
                            return player;

                        }
                    }
                    else if(symbol == SDLK_5){
                        if(playerNum==1){
                            Player* player = new Redman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/redmanright.png");
                            return player;
                        }else{
                            Player* player = new Redman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/redmanleft.png");
                            return player;

                        }
                    }
                    else if(symbol == SDLK_6){
                        if(playerNum==1){
                            Player* player = new Mintman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/mintmanright.png");
                            return player;
                        }else{
                            Player* player = new Mintman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/mintmanleft.png");
                            return player;
                        }
                    }
                    else if(symbol == SDLK_7){
                        if(playerNum==1){
                            Player* player = new Greenman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/greenmanright.png");
                            return player;
                        }else{
                            Player* player = new Greenman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/greenmanleft.png");
                            return player;

                        }
                    }
                    else if(symbol == SDLK_8){
                        if(playerNum==1){
                            Player* player = new Bigman(moverLeft,healthLeft,"right");
                            theGame->setAssetsOne("playerimg/bigmanright.gif");
                            return player;
                        }else{
                            Player* player = new Bigman(moverRight,healthRight,"left");
                            theGame->setAssetsTwo("playerimg/bigmanleft.gif");
                            return player;
                        }
                    }

                }
            }

            theGame->drawBg();


            SDL_Delay(100);
        }
        cout<<"exiting the loop"<<endl;
        
    }



private:
    Game* theGame;
};