#include <bits/stdc++.h>

#include "instruction.h"
#include "ScreenSize.h"
#include "init.h"
#include "close.h"
#include "credit.h"
#include "Menu.h"
#include "GameLoading.h"
#include "highscore.h"

SDL_Window* gWindow = NULL ; /// initialization window
SDL_Renderer* gRenderer = NULL ; /// initialization renderer

int state = 4 ; /// game status

int main(int argc, char* argv[]) {

    if (init(gWindow, gRenderer)) { /// initialization
        while (state != -1) {
            switch(state) {
                case 0: {
                    Menu(state, gRenderer) ;
                    break ;
                }
                case 1: {
                    GameLoading(state, gRenderer) ;
                    break ;
                }
                case 2:{
                    //Option(state, gRenderer) ;
                    break ;
                }
                case 3:{
                    Instruction(state, gRenderer) ;
                    break ;
                }
                case 4:{
                    HighScore(state, gRenderer) ;
                    break ;
                }
                case 5:{
                    Credit(state, gRenderer) ;
                    break ;
                }
            }
        }
    }

    close(gRenderer, gWindow) ;

    return 0 ;
}
