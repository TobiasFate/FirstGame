#include "option.h"

void Option(int &state, int &sound, SDL_Renderer* gRenderer) {

    /// initialize box

    Box BackBox = Box(400, 400, 800, 600) ;
    Box SoundBox = Box(100, 100, 300, 300) ;

    ////////////////////////////////////////////

    /// initialize Renderer

    SDL_Texture* ListTexture[2][2] ;

    ListTexture[1][0] = loadTexture("data/image/option_music_on.png", gRenderer) ;
    ListTexture[0][0] = loadTexture("data/image/option_music_off.png", gRenderer) ;
    ListTexture[0][1] = loadTexture("data/image/option_music_off_back.png", gRenderer) ;
    ListTexture[1][1] = loadTexture("data/image/option_music_on_back.png", gRenderer) ;

    ///////////////////////////////////////////////////

    /// start screen

    int quit = 0 ;

    renderTexture(ListTexture[sound][quit], gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;

    SDL_RenderPresent(gRenderer) ;

    /////////////////////////////////////////////////////////////////

    /// Mouse Event

    SDL_Event e ;

    bool quitloop = false ; int x, y ;

    while (!quitloop) {
        while (SDL_PollEvent(&e)) {

            /// close immidiately

            if (e.type == SDL_QUIT) {
                state = -1 ;
                quitloop = true ;
                break ;
            }

            /////////////////////////////////////////////////

            /// Mouse Motion and Mouse Pressed

            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x, &y) ;
                if (InsideBox(x, y, BackBox)) quit = 1 ;
                else quit = 0 ;
                if (InsideBox(x, y, SoundBox) && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    sound = 1 - sound ;
                }
                SDL_RenderClear(gRenderer) ;
                renderTexture(ListTexture[sound][quit], gRenderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT) ;
                SDL_RenderPresent(gRenderer) ;
                if (quit && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    state = 0 ;
                    quitloop = true ;
                    break ;
                }
            }
            /////////////////////////////////////////////////

        }
    }

    /////////////////////////////////////////////////////

    /// close

    for (int i = 0; i <= 1; ++ i) {
        for (int j = 0; j <= 1; ++ j) SDL_DestroyTexture(ListTexture[i][j]) ;
    }

    //////////////////////////////////////////////////

}
