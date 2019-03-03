#include "loadTexture.h"

/// loadTexture from a path-file

SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer) {
    SDL_Texture* newTexture = NULL ;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str()) ;
    if (loadedSurface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else {
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if(newTexture == NULL) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture ;
}

///////////////////////////////////////////////////////

/// RenderTexture to the Renderer in a rectangle with the top-left corner(x,y) w-width and h-height

void renderTexture(SDL_Texture *gTexture, SDL_Renderer *gRenderer, int x, int y, int w, int h) {
    SDL_Rect dst ;
    dst.x = x ;
    dst.y = y ;
    dst.w = w ;
    dst.h = h ;
    SDL_RenderCopy(gRenderer, gTexture, NULL, &dst) ;
}

//////////////////////////////////////////////////////////////////////////////////
