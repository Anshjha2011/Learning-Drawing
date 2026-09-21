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
                int rect_num = 0;
                int x,y;
                SDL_Rect rectangles[100];

                // Setting up the main loop
                while(is_open) {
                    // Breaking loop when Window is closed.
                    while(SDL_PollEvent(&e)) {
                        if(e.type == SDL_QUIT){
                            is_open = false;
                        }
                        if(e.type == SDL_MOUSEBUTTONDOWN){
                            rect_num++;
                            SDL_GetMouseState(&x,&y);
                        }
                    }

                    //Draw Background
                    SDL_SetRenderDrawColor(renderer,216,201,168,255);
                    SDL_RenderClear(renderer);
                            
                              

                    // Drawing 100*100 rectangles
                    rectangles[rect_num-1].x = x;
                    rectangles[rect_num-1].y = y;
                    rectangles[rect_num-1].w = 50;
                    rectangles[rect_num-1].h = 50;




                    
                    SDL_SetRenderDrawColor(renderer,0,0,255,255);
                    SDL_RenderFillRects(renderer,rectangles,rect_num);
                    SDL_RenderPresent(renderer);

                               
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


