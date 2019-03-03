#include "menu.h"

void Menu(int &state, SDL_Renderer* gRenderer) {

    /// 0: Current state
    /// 1: Game state
    /// 2: Option state
    /// 3: Instruction state
    /// 4: Highscore state
    /// 5: Credit state
    /// 6: Quit state

    /// initialize texture

    SDL_Texture* ListTexture[7] ;

    ListTexture[0] = loadTexture("data/image/menu.png", gRenderer) ;
    ListTexture[1] = loadTexture("data/image/menu_gameloading.png", gRenderer) ;
    ListTexture[2] = loadTexture("data/image/menu_option.png", gRenderer) ;
    ListTexture[3] = loadTexture("data/image/menu_instruction.png", gRenderer) ;
    ListTexture[4] = loadTexture("data/image/menu_highscore.png", gRenderer) ;
    ListTexture[5] = loadTexture("data/image/menu_credit.png", gRenderer) ;
    ListTexture[6] = loadTexture("data/image/menu_quit.png", gRenderer) ;

    ////////////////////////////////////////////////////////////

    /// initialize Box

    Box ListBox[7] ;

    for (int i = 1; i <= 6; ++ i) {
        ListBox[i] = Box(100 * (i - 1) + 1, 100 * (i - 1) + 1, 100 * i, 100 * i) ;
    }

    //////////////////////////////////////////////////////////////////

    /// Start Screen

    renderTexture(ListTexture[0], gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;

    SDL_RenderPresent(gRenderer) ;

    ////////////////////////////////////////////////////////////////////

    /// Mouse Event

    bool QuitLoop = false ;
    SDL_Event e ;

    int x, y ; int curTexture = 0 ;

    while (!QuitLoop) {

        while (SDL_PollEvent(&e)) {

            /// Close Immidiately

            if (e.type == SDL_QUIT) {
                QuitLoop = true ;
                state = -1 ;
                break ;
            }

            ////////////////////////////////////////

            /// Mouse Motion and Mouse Pressed

            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y) ;
                int NextTexture = 0 ;
                for (int i = 1; i <= 6; ++ i) if (InsideBox(x, y, ListBox[i])) NextTexture = i ;
                if (curTexture != NextTexture) {
                    SDL_RenderClear(gRenderer) ;
                    curTexture = NextTexture ;
                    renderTexture(ListTexture[curTexture], gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                    SDL_RenderPresent(gRenderer) ;
                }
                if (curTexture && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    state = curTexture ;
                    QuitLoop = true ;
                    break ;
                }
            }

            ///////////////////////////////////////////////////////////////////

        }
    }

    ////////////////////////////////////////////////////////////////////////

    /// Close

    for (int i = 0; i <= 6; ++ i) SDL_DestroyTexture(ListTexture[i]) ;

    //////////////////////////////////////////

}
