#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(int argc,char* argv[]){

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL failed to intialize Error:- %s",SDL_GetError());
    }
    else {
        window = SDL_CreateWindow("BoxDrop",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,0);
        if (window == NULL){
            printf("SDL failed to create a window Error :- %s",SDL_GetError());}
        else
            {
            bool Window_Open = true;
            SDL_Event e;
            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (renderer == NULL){
                printf("SDL failed to Create Renderer Error :- %s",SDL_GetError());}
            
            while (Window_Open){
                if (SDL_PollEvent(&e) && e.type == SDL_QUIT){
                    Window_Open = false;
                }
                //This is where the code goes
                SDL_Event mouse_in;

                SDL_SetRenderDrawColor(renderer,216,201,168,255);
                SDL_RenderClear(renderer);
                SDL_Rect first_rectangle = {300,200,200,200};
                SDL_SetRenderDrawColor(renderer,0,0,255,255);
                SDL_RenderFillRect(renderer,&first_rectangle);
                SDL_RenderPresent(renderer);
                
                if(SDL_PollEvent(&mouse_in) && mouse_in.type == SDL_MOUSEBUTTONDOWN){
                    while (Window_Open){
                        if(SDL_PollEvent(&e) && e.type == SDL_QUIT){
                            Window_Open = false;
                        }

                        SDL_SetRenderDrawColor(renderer,216,201,168,255);
                        SDL_RenderFillRect(renderer,&first_rectangle);
                        SDL_RenderPresent(renderer);
                    }


                }

            }
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            }
    }
}
