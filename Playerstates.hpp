#pragma once
#include "SDL.h"

/**
 *  Structure that holds all animation states for a character
 * 
 * This structure contains SDL_Rect definitions for different character states:
 * - Walking animations (3 frames)
 * - Attack animations (punch and kick)
 * - Hit reaction animation
 * - Current state of the character
 */
struct Playerstates {
    SDL_Rect srcRect;    // Current sprite rectangle being displayed
    SDL_Rect walkOne;    // First frame of walking animation
    SDL_Rect walkTwo;    // Second frame of walking animation
    SDL_Rect walkThree;  // Third frame of walking animation
    SDL_Rect kickRect;   // Kick attack animation frame
    SDL_Rect punchRect;  // Punch attack animation frame
    SDL_Rect hitRect;    // Hit/damage reaction animation frame
    Playerstates() = default;
    Playerstates(SDL_Rect srcRect, SDL_Rect walkOne,SDL_Rect walkTwo,SDL_Rect walkThree,SDL_Rect kickRect,SDL_Rect punchRect,SDL_Rect hitRect):
                                                                                                                    srcRect(srcRect),
                                                                                                                    walkOne(walkOne),
                                                                                                                    walkTwo(walkTwo),
                                                                                                                    walkThree(walkThree),
                                                                                                                    kickRect(kickRect),
                                                                                                            punchRect(punchRect),
                                                                                                                    hitRect(hitRect)
                                                                                                                    {}
};