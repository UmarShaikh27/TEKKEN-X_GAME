#include <iostream>
#include "SDL.h"

/**
 *  Timer class for managing game time and pausing functionality
 * 
 * Provides functionality for:
 * - Starting and stopping game time
 * - Pausing and resuming gameplay
 * - Tracking elapsed time
 * - Managing game state timing
 */
class Timer {
public:
    /**
     *  Constructor initializes timer in stopped state
     */
    Timer() : startTicks(0), pausedTicks(0), paused(false), started(false) {}    /**
     *  Starts the timer
     * 
     * Initializes the timer and begins counting from the current moment.
     * Also ensures the timer isn't paused when starting.
     */
    void start() {
        started = true;
        paused = false;
        startTicks = SDL_GetTicks();
    }

    /**
     *  Stops the timer
     * 
     * Completely stops the timer and resets its state.
     * Different from pause as this is a full reset.
     */
    void stop() {
        started = false;
        paused = false;
    }

    /**
     *  Pauses the timer
     * 
     * Temporarily halts the timer while preserving the elapsed time.
     * Only works if the timer is currently running and not already paused.
     */
    void pause() {
        if (started && !paused) {
            paused = true;
            pausedTicks = SDL_GetTicks() - startTicks;
        }
    }

    // Resume timer and game
    void resume() {
        if (paused) {
            paused = false;
            startTicks = SDL_GetTicks() - pausedTicks;
            pausedTicks = 0;
        }
    }

    // Get the current time on the timer
    Uint32 getTicks() const {
        Uint32 time = 0;

        if (started) {
            if (paused) {
                time = pausedTicks;
            } else {
                time = SDL_GetTicks() - startTicks;
            }
        }

        return time;
    }

    // Check if the timer is started
    bool isStarted() const {
        return started;
    }

    // Check if the timer is paused
    bool isPaused() const {
        return paused && started;
    }

private:
    Uint32 startTicks;   // The ticks recorded when the timer starts
    Uint32 pausedTicks;  // The ticks recorded when the timer is paused
    bool paused;         // Flag indicating whether the timer is paused
    bool started;        // Flag indicating whether the timer is started
};
