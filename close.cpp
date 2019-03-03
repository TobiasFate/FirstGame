#include "close.h"

void close(SDL_Renderer* &gRenderer, SDL_Window* &gWindow) {
    SDL_DestroyRenderer(gRenderer) ;
    gRenderer = NULL ;
    SDL_DestroyWindow(gWindow) ;
    gWindow = NULL ;
    IMG_Quit() ;
    TTF_Quit() ;
    SDL_Quit() ;
}
