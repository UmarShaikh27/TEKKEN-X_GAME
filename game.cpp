#pragma once
#include "game.hpp"


#include <iostream>
using namespace std;
const Uint8* keyState;
// Mix_Music *backgroundMusic = NULL;
// Mix_Chunk *onehigh=NULL;
// Mix_Chunk *twohigh=NULL;
// Mix_Chunk *threehigh=NULL;
// Mix_Chunk *fourhigh=NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;
	// if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	// {
    // 	printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    // 	success = false;
	// }

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				// if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				// {
				// 	printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
				// 	success = false;
				// }	

			}
		}
		
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	// assetsOne = loadTexture("playerimg/redmanright.png");
	// assetsTwo = loadTexture("playerimg/kakashileft.png");
    // gTexture = loadTexture("habib.png");
	greentexture=loadTexture("green.png");
	whitetexture=loadTexture("white.png");
		return success;
	}


	// if(assetsOne==NULL || assetsTwo== NULL || gTexture==NULL)
	// if(gTexture==NULL)
    // {
    //     printf("Unable to run due to error: %s\n",SDL_GetError());
    //     success =false;
    // }
	
	// return success;


void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assetsOne);
	SDL_DestroyTexture(assetsTwo);
	assetsOne=NULL;
	assetsTwo=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	// Mix_FreeChunk(onehigh);
	// Mix_FreeChunk(twohigh);
	// Mix_FreeChunk(threehigh);
	// Mix_FreeChunk(fourhigh);
	// Mix_FreeMusic(backgroundMusic);
	// Mix_FreeMusic(bgMusic);
	// bgMusic = NULL;
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	// Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	

	return newTexture;
}

void Game::drawBg(){
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); 
	SDL_RenderPresent(gRenderer);

}

void Game::changeBg(string str){
	gTexture=loadTexture(str);
};
void Game::setAssetsOne(string str){
	assetsOne=loadTexture(str);
};
void Game::setAssetsTwo(string str){
	assetsTwo=loadTexture(str);
};
void Game::endGame(Player* playerOne,Player* playerTwo){
	playerOne->deletePlayer();
	playerTwo->deletePlayer();
	cout<<"Player data deleted"<<endl;
	delete playerOne;
	playerOne = nullptr;
	delete playerTwo;
	playerTwo = nullptr;
}
void Game::run()
{
	startup gameStart(this);
	Player* playerOne = gameStart.choosePlayers(1);
	cout<<"Player one chosen"<<endl;
	SDL_Delay(50);
	Player* playerTwo = gameStart.choosePlayers(2);
	// playerTwo->flipstate=false;
	cout<<"Player two chosen"<<endl;
	gameStart.drawGrounds();
	

	bool quit = false;
	SDL_Event e;
	// Player* playerOne = new Bluewoman{{412,173,61,108},{100,300,150,270}, {412,173,61,108} , {413,45 ,63, 88}, {348,54,52,81},{101,40,60,94},{753,167,90,113},{20,338,67,94},{10,10,300,30}};
    // Player playerTwo = new Graywoman{{429,127,64,106},{800,300,150,270}, {429,127,64,106} , {352,128 ,64, 108}, {271,131,64,107},{252,259,74,113},{216,529,114,92},{336,636,61,104},{685,10,300,30}};

	// Player* playerOne = new Redman{{100,300,150,270},{10,10,300,30},"right"};
	// Player* playerTwo = new Kakashi{{800,300,150,270},{685,10,300,30},"left"};
    // Player playerTwo = new Graywoman{{429,127,64,106},{800,300,150,270}, {429,127,64,106} , {352,128 ,64, 108}, {271,131,64,107},{252,259,74,113},{216,529,114,92},{336,636,61,104},{685,10,300,30}};

	int state=0;
	int longvar1=0;
	int longvar2=0;
	int kickvar1=0;
	int kickvar2=0;
	int played=0;
	int gamestate=0;
	int restart = 0;

	Timer timer;
	// timer.start();
	int progressBarWidth = 200;
    int progressBarHeight = 20;
    int maxTime = 20000;  // 20 seconds in milliseconds
	int initState = 0;

	while(!quit)
	{
		
		//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if(e.type == SDL_QUIT)
				{
					quit = true;
				}
				if(e.type == SDL_KEYUP){
					if(e.key.keysym.sym == SDLK_q){
						longvar2=0;
						playerOne->unPunch(playerTwo);
					}
					if(e.key.keysym.sym == SDLK_p ){
						longvar1=0;
						playerTwo->unPunch(playerOne);
					}
					if(e.key.keysym.sym == SDLK_k ){
						kickvar1=0;
						playerTwo->unkick(playerOne);
					}
					if(e.key.keysym.sym == SDLK_e ){
						kickvar2=0;
						playerOne->unkick(playerTwo);
					}
					
				}
				if(e.type == SDL_KEYDOWN){
					if(e.key.keysym.sym == SDLK_v){
						if(playerOne->flipstate==true)
						{
							assetsOne = loadTexture(playerOne->getterright());
							
						}
						else
						{
							assetsOne = loadTexture(playerOne->getterleft());
						}
						playerOne->flip();
						if(playerTwo->flipstate==true)
						{
							assetsTwo = loadTexture(playerTwo->getterleft());
						}
						else
						{
							assetsTwo = loadTexture(playerTwo->getterright());
						}
						playerTwo->flip();
					}
				}
				

			}

			// Update the timer
			Uint32 elapsedTime = timer.getTicks();

			// Check if two minutes have passed
			if (elapsedTime >= maxTime) {
				std::cout << "Game over! Two minutes have passed." << std::endl;
				quit = true;
			}

			// Render the progress bar
			// float progress = static_cast<float>(elapsedTime) / maxTime;
			// int currentProgressBarWidth = static_cast<int>(progress * progressBarWidth);

			// SDL_Rect progressBarRect = {10, 10, currentProgressBarWidth, progressBarHeight};
			// SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 255);  // Green color
			// SDL_RenderFillRect(gRenderer, &progressBarRect);


			keyState = SDL_GetKeyboardState(NULL);

			if(keyState[SDL_SCANCODE_A]){
				if(playerOne->moverRect.x > 0){
					playerOne->moverRect.x-=10;
				}
				playerOne->changeState();
			}
			if(keyState[SDL_SCANCODE_D]){
				if(playerOne->moverRect.x + playerOne->moverRect.w < 1000){
					playerOne->moverRect.x+=10;
				}
				
				playerOne->changeState();
			}
			if(keyState[SDL_SCANCODE_E]){
				// playerOne.srcRect = playerOne.kickRect;
				if(kickvar2==0)
				{
				playerOne->kickattack(playerTwo);
				kickvar2=1;
				}

			}
			if(keyState[SDL_SCANCODE_Q]){
				if(longvar2==0)
				{
				playerOne->punchAttack(playerTwo);
				longvar2=1;
				// playerTwo.healthrect.w-=5;
				// playerTwo.healthrect.x+=5; RECENT
				// Mix_PlayChannel( -1, gHigh, 0 );
				}
			}

			if(keyState[SDL_SCANCODE_LEFT]){
				if(playerTwo->moverRect.x > 0){
					playerTwo->moverRect.x-=10;
				}
				playerTwo->changeState();
			}
			if(keyState[SDL_SCANCODE_RIGHT]){
				if(playerTwo->moverRect.x + playerTwo->moverRect.w < 1000){
					playerTwo->moverRect.x+=10;
				}
				
				playerTwo->changeState();
			}
			if(keyState[SDL_SCANCODE_K]){
				// playerTwo.srcRect = playerTwo.kickRect;
				if(kickvar1==0)
				{
				playerTwo->kickattack(playerOne);
				// Mix_PlayChannel(-1, twohigh, 0);				

				kickvar1=1;
				}
			}
			if(keyState[SDL_SCANCODE_P]){
				if(longvar1==0)
				{
				playerTwo->punchAttack(playerOne);
				longvar1=1;
				}
			}
			
			

			drawBg();

			//Draws characters on renderer
			
			
			SDL_RenderCopy(gRenderer, assetsOne, &playerOne->Data->srcRect , &playerOne->moverRect);
			SDL_RenderCopy(gRenderer, assetsTwo, &playerTwo->Data->srcRect , &playerTwo->moverRect);
			SDL_RenderCopy(gRenderer, whitetexture, &whiteSRCrect, &whiteMOVErect1 );
			SDL_RenderCopy(gRenderer, whitetexture, &whiteSRCrect, &whiteMOVErect2 );
			SDL_RenderCopy(gRenderer, greentexture, &greenSRCrect, &playerOne->healthrect );
			SDL_RenderCopy(gRenderer, greentexture, &greenSRCrect, &playerTwo->healthrect );
			
	
			
			// playerOne->healthrect.w = -1;

			if(playerOne->healthrect.w<=0 || playerTwo->healthrect.w<=0)
			{
				
				if(playerTwo->healthrect.w<=0){
					changeBg("player1wins.png");
				}else{
					changeBg("player2wins.png");
				}
				bool quitloop =false;
				while(!quitloop){
					while( SDL_PollEvent( &e ) != 0 ){
						drawBg();
						if(e.type == SDL_QUIT)
						{
							quitloop = true;
							close();
						}
						if(e.type == SDL_KEYDOWN) {
							if(e.key.keysym.sym == SDLK_1){
								quitloop = true;
							}
						}
						
					}
				}
				
				endGame(playerOne,playerTwo);
			
				cout<<"Game end"<<endl;
				gameStart.restart();
				// cout<<playerOne->healthrect.h<<endl;


			}
			
			// createCharacters(gRenderer, assetsOne,assetsTwo); 

			//**********************
			SDL_RenderPresent(gRenderer); //displays the updated renderer

			SDL_Delay(50);	//causes sdl engine to delay for specified miliseconds
		


	}		
}