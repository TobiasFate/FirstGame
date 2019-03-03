#ifndef LOADTEXTURE_H_INCLUDED
#define LOADTEXTURE_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer) ;

void renderTexture(SDL_Texture *gTexture, SDL_Renderer *gRenderer, int x, int y, int h, int w) ;

#endif // LOADTEXTURE_H_INCLUDED
