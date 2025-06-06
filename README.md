# TEKKEN-X

A 2D fighting game built with SDL2, featuring multiple characters and interactive combat mechanics.

## Quick Start

For immediate gameplay, you can use the pre-built `Game.exe` executable included in this repository. Simply download and run it!

## Features

- Multiple playable characters including:
  - Blue Woman
  - Gray Woman
  - Kakashi
  - Blue Man
  - Red Man
  - Mint Man
  - Green Man
  - Big Man
- Real-time combat system with punches and kicks
- Interactive character selection screen
- Health bars with dynamic damage system
- Background music and combat sound effects
- Victory/defeat screens

## Controls

Player 1:
- A/D: Move left/right
- Q: Punch
- E: Kick
- V: Flip character direction

Player 2:
- LEFT/RIGHT Arrow: Move left/right
- P: Punch
- K: Kick
- V: Flip character direction

## Building from Source

### Prerequisites

- MinGW-w64 with G++ compiler
- SDL2 development libraries:
  - SDL2
  - SDL2_image
  - SDL2_mixer
  - SDL2_ttf

### Required Files

The project includes:
- `include/SDL2/`: Header files
- `lib/`: Library files
- `playerimg/`: Character sprites
- `hits/`: Sound effects and music

### Building Instructions

1. Ensure MinGW-w64 is installed and properly configured
2. Make sure SDL2 DLLs are either in your system PATH or in the game directory:
   - SDL2.dll
   - SDL2_image.dll
   - SDL2_mixer.dll
   - SDL2_ttf.dll

Build using either method:

Using G++ directly:
```powershell
g++ *.cpp -I./include -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o Game.exe
```

Or using VS Code:
1. Open the project in VS Code
2. Press Ctrl+Shift+B to build
3. The executable will be created as `Game.exe`

## Gameplay

1. Run `Game.exe`
2. Select your character using number keys (1-8)
3. Fight against your opponent
4. Win by depleting your opponent's health bar
5. Press 1 to restart after a match

## Troubleshooting

If you encounter issues:
1. Verify all SDL2 DLLs are present
2. Check that image and sound files are in their correct directories
3. Ensure MinGW is properly configured
4. Make sure your graphics drivers are up to date

## Credits

This game was created as an Object-Oriented Programming project at Habib University. Assets used in this project (sound effects and sprite sheets) are from various open-source game development resources.
