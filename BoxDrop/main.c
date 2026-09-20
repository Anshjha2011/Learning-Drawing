#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(int argc,char* argv[]){

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    //Intializing SDL
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL failed to intialize Error:- %s",SDL_GetError());
    }
    else {
        //Creating Window
        window = SDL_CreateWindow("BoxDrop",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,0);
        if (window == NULL){
            printf("SDL failed to create a window Error :- %s",SDL_GetError());}
        else
            {
            //Setting up variables for main loop and event loop
            bool Window_Open = true;
            SDL_Event e;

            // Creating Renderer
            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (renderer == NULL){
                printf("SDL failed to Create Renderer Error :- %s",SDL_GetError());}
            
            //Here Program will enter after checking for error
            while (Window_Open) {
                if (SDL_PollEvent(&e) && e.type == SDL_QUIT){  //If this is true for even one the main loop runs only one time more....
                    Window_Open = false;
                }
                //This is where the code goes

                //Setting the variables for the mouseclick,Rectangle,Positions of cursor and Getting the position in the variables
                SDL_Event mouse_in;
                SDL_Rect first_rectangle = {300,200,200,200};
                int x,y;
                SDL_GetMouseState(&x,&y);
                
                // Setting the loop to change color when hovering over box
                while(x >= 300 && x <= 500 && y >= 200 && y <= 400 && Window_Open){   //Condition to check whether the cursor hovers over box or not and Window_Open for managing the crash 
                    SDL_GetMouseState(&x,&y); //To always checking if cursor is still on box
                    
                    //Change in color
                    SDL_SetRenderDrawColor(renderer,0,255,0,255);
                    SDL_RenderFillRect(renderer,&first_rectangle);
                    SDL_RenderPresent(renderer);
                    
                    //Checking if window is open or not
                     if (SDL_PollEvent(&e) && e.type == SDL_QUIT){
                    Window_Open = false;
                }
                    
                }

                //Main Loop When the cursor is not on the box
                SDL_SetRenderDrawColor(renderer,216,201,168,255);
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer,0,0,255,255);
                SDL_RenderFillRect(renderer,&first_rectangle);
                SDL_RenderPresent(renderer);
                
                //Checking if mouse button is clicked or not 
                if(SDL_PollEvent(&mouse_in) && mouse_in.type == SDL_MOUSEBUTTONDOWN){

                    //If clicked enter a different loop when box is disappeared
                    while (Window_Open){ //Runs till Window is open if not breaked
                        if(SDL_PollEvent(&e) && e.type == SDL_QUIT){
                            Window_Open = false;
                        }
                        //Changing visibility
                        SDL_SetRenderDrawColor(renderer,216,201,168,255);
                        SDL_RenderFillRect(renderer,&first_rectangle);
                        SDL_RenderPresent(renderer);
                        SDL_Event mouse_in2;


                        //Checking If mouse is clicked again to exit the loop to reappear box
                        if(SDL_PollEvent(&mouse_in2) && mouse_in2.type == SDL_MOUSEBUTTONDOWN){
                            break;
                        }
                    }
                }

            }

            //Destroying Renderer and Window After window is closed 
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            }
    }
}
