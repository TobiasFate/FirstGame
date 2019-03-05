#include "highscore.h"

void HighScore(int &state, SDL_Renderer* gRenderer) {

    /// initialize Font

    TTF_Font* gFont = NULL ;

    gFont = TTF_OpenFont("data/font/lazy.ttf", 30) ;

    if (gFont == NULL) {
        std::cout << "Failed to load Font" << std::endl ;
        state = -1 ;
        return ;
    }

    //////////////////////////////////////////////////////////

    /// initialize texture

    SDL_Texture* HighScoreTexture = loadTexture("data/image/highscore.png", gRenderer) ;
    SDL_Texture* BackTexture = loadTexture("data/image/highscore_back.png", gRenderer) ;

    /////////////////////////////////////////////////////////////

    /// initialize BackBox

    Box BackBox = Box(200, 200, 400, 400) ;

    //////////////////////////////////////////////////////////////

    /// initialize color

    SDL_Color textColor = {0, 0, 0} ;

    ////////////////////////////////////////////////////////////

    /// read highscore

    std::ifstream myfile ("data/highscore/highscore.txt") ;

    std::string textureText ;

    if (!myfile.is_open()) {
        std::cout << "Can't open file highscore text" << std::endl ;
        state = -1 ;
        return ;
    }

    myfile >> textureText ;


    ///////////////////////////////////////////////////////////////////////

    /// initialize textSurface

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor) ;

    if (textSurface == NULL) {
        std::cout << "Can't load textSurface" << std::endl ;
        state = -1 ;
        return ;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface) ;

    SDL_FreeSurface(textSurface) ;

    /////////////////////////////////////////////////////////////////////

    /// Started Texture

    renderTexture(HighScoreTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;

    renderTexture(textTexture, gRenderer, 100, 100, 200, 200) ;

    SDL_RenderPresent(gRenderer) ;

    //////////////////////////////////////////////////////////////////////

    /// Mouse Event

    SDL_Event e ;

    int curState = 0, NextState, x, y ;

    bool quit = false ;

    while (!quit) {
        while (SDL_PollEvent(&e)) {

            /// Close Immediately

            if (e.type == SDL_QUIT) {
                state = -1 ;
                quit = true ;
                break ;
            }

            ////////////////////////////////////////////////////

            /// Mouse Motion and Mouse Pressed

            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {

                SDL_GetMouseState(&x, &y) ;
                if (InsideBox(x, y, BackBox)) NextState = 1 ;
                else NextState = 0 ;

                if (curState != NextState) {
                    SDL_RenderClear(gRenderer) ;
                    curState = NextState ;
                    if (curState) renderTexture(BackTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    else renderTexture(HighScoreTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    renderTexture(textTexture, gRenderer, 100, 100, 200, 200) ;
                    SDL_RenderPresent(gRenderer) ;
                }

                if (curState && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    state = 0 ;
                    quit = true ;
                    break ;
                }

            }

            ///////////////////////////////////////////////////////////////

        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////

    /// close

    SDL_DestroyTexture(HighScoreTexture) ;
    SDL_DestroyTexture(BackTexture) ;
    SDL_DestroyTexture(textTexture) ;

    /////////////////////////////////////////////////////////////////////////////////////////

}
