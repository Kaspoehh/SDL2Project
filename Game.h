//
// Created by Kasper on 30/03/2022.
//

#ifndef SDL2PROJECT_GAME_H
#define SDL2PROJECT_GAME_H

#include <iostream>
#include <ostream>

#include "SDL.h"
#include "SDL_image.h"

class Game {

public:
    Game();
    ~Game();

    void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();

    void Clean();

    inline bool IsRunning(){return isRunning; }

private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //SDL2PROJECT_GAME_H
