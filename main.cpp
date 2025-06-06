#include "game.hpp"

/**
 *  Main entry point for the TEKKEN-X fighting game
 * 
 * Program flow:
 * 1. Creates game instance
 * 2. Initializes SDL and game resources
 * 3. Loads media assets (sprites, sounds)
 * 4. Runs the main game loop
 * 5. Performs cleanup on exit
 * 
 * @param argc Argument count (unused)
 * @param argv Argument values (unused)
 * @return 0 on successful execution, non-zero on error
 */
int main(int argc, char *argv[]){
    Game game;
    srand(time(NULL));  // Initialize random number generator for game events
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !game.loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }
    
    game.run();
    game.close();

    return 0;
}

