#include "GameLoading.h"

void GameLoading(int &state, SDL_Renderer* gRenderer)
{
	//Current background :)
	SDL_Texture* gBackground = loadTexture("jungle.png", gRenderer);
	//Current Main Object
	SDL_Texture* gMainObj = loadTexture("monkey.png", gRenderer);

	//Vi tri ban dau cua MainObj
	int pos_x = 0;
	int pos_y = 0;

		state = -1 ;
//	if (quit) state = -1;
}
