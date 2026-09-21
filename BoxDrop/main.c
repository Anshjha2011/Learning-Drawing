#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(int argc,char* argv[]){

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    //Intializing SDL
    if (SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL failed to intialize Error:- %s",SDL_GetError());
        return 0;
    }
    else {
        //Creating Window
        window = SDL_CreateWindow("BoxDrop",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,0);
        if (window == NULL){
            printf("SDL failed to create a window Error :- %s",SDL_GetError());
            return 0;}
        else
            {
            //Setting up variables for main loop and event inputs
            bool Window_Open = true;
            SDL_Event e;
            bool box_is_visible = true;



            // Creating Renderer
            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

            if (renderer == NULL){
                printf("SDL failed to Create Renderer Error :- %s",SDL_GetError());
                return 0;}
            else {
            //Here Program will enter after checking for error
            while (Window_Open) {

                while(SDL_PollEvent(&e)){  //The SDL Polls the event queue until it empties and check for quit and clicks
                    if(e.type == SDL_QUIT){
                        Window_Open = false;
                        break;
                    }
                    else if(e.type == SDL_MOUSEBUTTONDOWN && box_is_visible == true){
                        box_is_visible = false;
                        break;
                    }
                    else if(e.type == SDL_MOUSEBUTTONDOWN && box_is_visible == false){
                        box_is_visible = true;
                    }
                }

                //Setting the variables for the Rectangle,Positions of cursor and Getting the position in the variables
                SDL_Rect first_rectangle = {300,200,200,200};
                int x,y;
                SDL_GetMouseState(&x,&y);
                SDL_SetRenderDrawColor(renderer,216,201,168,255);
                SDL_RenderClear(renderer);
                
                // if hovering over box and box is visible change color
                if(x >= 300 && x <= 500 && y >= 200 && y <= 400 && box_is_visible){   //Condition to check whether the cursor hovers over box or not and Window_Open for managing the crash 
                    //Change in color
                    SDL_SetRenderDrawColor(renderer,0,255,0,255);
                    SDL_RenderFillRect(renderer,&first_rectangle);     
                }               
                else if(box_is_visible == true){
                    // When visible and cursor not on box
                    SDL_SetRenderDrawColor(renderer,0,0,255,255);
                    SDL_RenderFillRect(renderer,&first_rectangle);
                }
                else if(box_is_visible == false){            
                    //Changing visibility when not visible
                    SDL_SetRenderDrawColor(renderer,216,201,168,255);
                    SDL_RenderFillRect(renderer,&first_rectangle);
                }

                SDL_RenderPresent(renderer); //rendering once
            }
            //Destroying Renderer and Window After window is closed 
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
    }
    }
}
}
