#pragma once
#include "SDL.h"

struct Playerstates{
    SDL_Rect srcRect,walkOne,walkTwo,walkThree,kickRect,punchRect,hitRect;
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