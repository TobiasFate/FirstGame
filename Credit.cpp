#include "Credit.h"

void Credit(int &state, SDL_Renderer* gRenderer) {

    /// Initialize BackBox

    Box BackBox = Box(400, 400, 800, 600) ;

    ///////////////////////////////////////////

    /// Initialize Texture

    SDL_Texture* CreditTexture = loadTexture("data/image/Credit.png", gRenderer) ;
    SDL_Texture* BackTexture = loadTexture("data/image/credit_back.png", gRenderer) ;

    if (CreditTexture == NULL || BackTexture == NULL) {
        std::cout << "Can't load Credit Image" << std::endl ;
        state = -1 ;
        return ;
    }

    ///////////////////////////////////////////

    /// Start Screen

    renderTexture(CreditTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;

    SDL_RenderPresent(gRenderer) ;

    ///////////////////////////////////////////

    /// Mouse Event

    bool quit = false, menu = false, Back = false, changeBack = false;

    SDL_Event e ;

    int x, y ;

    while (!quit && !menu) {

        while (SDL_PollEvent(&e)) {

            /// Close Immidiately

            if (e.type == SDL_QUIT) {
                quit = true ;
                break ;
            }

            //////////////////////////////////

            /// Mouse Motion and Mouse Pressed

            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {

                SDL_GetMouseState(&x, &y) ;
                if (InsideBox(x, y, BackBox)) {
                    if (!Back) Back = true, changeBack = true ;
                }
                else {
                    if (Back) Back = false, changeBack = true ;
                }

                if (changeBack) {
                    SDL_RenderClear(gRenderer) ;
                    changeBack = false ;
                    if (!Back) renderTexture(CreditTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    else renderTexture(BackTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    SDL_RenderPresent(gRenderer) ;
                }

                if (Back && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    menu = true ;
                    break ;
                }

            }
            ////////////////////////////////////////////////////////
        }
    }

    ////////////////////////////////

    /// Update State

    if (quit) state = -1 ;
    if (menu) state = 0 ;

    //////////////////////////////////

    /// Close

    SDL_DestroyTexture(CreditTexture) ;
    SDL_DestroyTexture(BackTexture) ;

    /////////////////////////////////////
}
