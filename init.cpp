#include "init.h"

bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer) {

    /// Initialize Window

    gWindow = SDL_CreateWindow("Instruction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) ;
    if( gWindow == NULL ){
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false ;
    }

    ///////////////////////////////////////////////

    /// Initialize Renderer

    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if (gRenderer == NULL) {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false ;
    }

    /////////////////////////////////////////////////

    /// Initialize PNG Loading

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false ;
    }

    //////////////////////////////////////////////

    /// Initialize SDL_ttf

    if (TTF_Init() == -1) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() ) ;
        return false ;
    }

    /////////////////////////////////////////////

    return true ;
}
