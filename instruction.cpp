#include "instruction.h"

void Instruction(int &state, SDL_Renderer* gRenderer) {

    /// Initialize BackBox

    Box BackBox = Box(400, 400, 800, 600) ;

    //////////////////////////////////////////

    /// Initialize Texture

    SDL_Texture* InstructionTexture = loadTexture("data/image/instruction.png", gRenderer) ;
    SDL_Texture* BackTexture = loadTexture("data/image/instruction_back.png", gRenderer) ;

    if (InstructionTexture == NULL || BackTexture == NULL) {
        std::cout << "Can't load Instruction Image" << std::endl ;
        state = -1 ;
        return ;
    }

    ////////////////////////////////////////////////

    /// Start Texture

    renderTexture(InstructionTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;

    SDL_RenderPresent(gRenderer) ;

    /////////////////////////////////////////////////

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

            /// Mouse motion and Mouse Pressed

            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {

                SDL_GetMouseState(&x, &y) ;

                std::cout << x << " " << y << std::endl ;

                if (InsideBox(x, y, BackBox)) {
                    if (!Back) Back = true, changeBack = true ;
                }
                else {
                    if (Back) Back = false, changeBack = true ;
                }

                if (changeBack) {
                    SDL_RenderClear(gRenderer) ;
                    changeBack = false ;
                    if (!Back) renderTexture(InstructionTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    else renderTexture(BackTexture, gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    SDL_RenderPresent(gRenderer) ;
                }

                if (Back && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    menu = true ;
                    break ;
                }

            }

            //////////////////////////////////////////////////////////////

        }
    }

    ////////////////////////////////////////////

    /// Update State

    if (quit) state = -1 ;
    if (menu) state = 0 ;

    ////////////////////////////////////////////

    /// Close

    SDL_DestroyTexture(InstructionTexture) ;
    SDL_DestroyTexture(BackTexture) ;

    ///////////////////////////////////////////

}
