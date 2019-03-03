#ifndef GAMELOADING_H_INCLUDED
#define GAMELOADING_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
//#include "MainObj.h"
#include "LoadTexture.h"
#include "Init.h"
#include "Close.h"
#include "ScreenSize.h"


void GameLoading(int &state, SDL_Renderer* gRenderer);

#endif // GAMELOADING_H_INCLUDED
