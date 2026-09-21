#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(int argc,char* argv[]){
    
    // Initializing SDL and Handling error.
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        printf(" Failed to Initialize SDL. More Info: %s\n",SDL_GetError());
        return 0;
    }
    else {
        //Creating Window and Handling error.
        SDL_Window* window = SDL_CreateWindow("BoxDrop",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,0);
    
        if (window == NULL) {
            printf(" Failed to Create Window. More Info: %s\n",SDL_GetError());
            return 0;
        }
        else {

            //Creating Renderer and Handling error.
            SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (renderer == NULL) {
                printf(" Failed to Create Renderer. More Info: %s\n",SDL_GetError());
                return 0;
            }
            else {
                //Everything Starts From Here, We Will Intialize is_open and SDL_Event for inputs
                SDL_Event e;
                bool is_open = true;

                // Setting up the main loop
                while(is_open) {
                    // Breaking loop when Window is closed.
                    while(SDL_PollEvent(&e)) {
                        if(e.type == SDL_QUIT){
                            is_open = false;
                        }
                    }

                    //Draw Background
                    SDL_SetRenderDrawColor(renderer,216,201,168,255);
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);
                    
                    // Foreground loop so Drawing Background doesn't clear rectangles
                    while(is_open){
                               
                        // Checking if window is closed or not for breaking the loop
                        while(SDL_PollEvent(&e)) {
                            if(e.type == SDL_QUIT){
                                is_open = false;
                            }
                            if(e.type == SDL_MOUSEBUTTONDOWN){

                                // Setting Up variable and storing position of cursor when clicked
                                int x,y;
                                SDL_GetMouseState(&x,&y);

                                // Drawing 100*100 rectangle at that location
                                SDL_Rect rectangle = {x,y,100,100};
                                SDL_SetRenderDrawColor(renderer,0,0,255,255);
                                SDL_RenderFillRect(renderer,&rectangle);
                                SDL_RenderPresent(renderer);

                            }
                        }   
                }
            }


            // Destroying Renderer
            SDL_DestroyRenderer(renderer);

    }
        // DestroyingWindow
        SDL_DestroyWindow(window);

        }
    // Shutting SDL systems
    SDL_Quit();
}
}

