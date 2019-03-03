#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <bits/stdc++.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "loadTexture.h"
#include "ScreenSize.h"

bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer) ;

#endif // INIT_H_INCLUDED
