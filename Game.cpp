//
// Created by hplap on 30/03/2022.
//

#include "Game.h"

SDL_Texture* playerTex;

//Constructor
Game::Game() {

}

//Deconstruction
Game::~Game() {

}

void Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;

    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialized" << std::endl;

        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    }

    window ? std::cout << "Window created!" << std::endl : std::cout << "Creating Window Went Wrong!" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);

    renderer ? isRunning = true, SDL_SetRenderDrawColor(renderer, 255,255,0,0) : isRunning = false;


    //Creating textures
    SDL_Surface* tempSurface = IMG_Load("Assets/Images/chartest.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
 //   //clean the surface
   // SDL_FreeSurface(tempSurface);
}

void Game::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
    }

}

void Game::Update()
{
    cnt++;
    std::cout << cnt << std::endl;
}

void Game::Render()
{
    SDL_RenderClear(renderer);

    //This is where we add stuff to render
   // SDL_RenderCopy(renderer, playerTex, NULL, NULL);

    SDL_RenderPresent(renderer);

}

void Game::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned up";
}