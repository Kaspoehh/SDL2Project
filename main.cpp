#include "SDL.h"
#include "Game.h"

Game *game = nullptr;

int main(int argc, char* args[])
{
    game = new Game();
    game->Init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    //Game loop
    while(game->IsRunning())
    {
        //User inputs
        game->HandleEvents();

        //Update Objects
        game->Update();

        //Render Objects
        game->Render();
    }

    game->Clean();

    //Quit
    return 0;
}
