#include "mainMenu.hpp"
#include "movement.hpp"
#include "game.hpp"

#include <raylib.h>
#include <iostream>

int menuStateSelected = 0;
const int backgroundWidth = 1280;
const int backgroundHeight = 780;


Rectangle fullscreenButton = { 10, 10, 100, 100 };


void mainMenu(Texture2D pill1,Texture2D fb,Texture2D fb_flap,Texture2D pill2,Texture2D Start_Button, Texture2D bg){
    if(menuStateSelected == 0){
        DrawText( "Asta e meniu ba", 0, 0 ,20 ,BLACK );
        DrawTexture(bg, 0, 0 ,WHITE);
        DrawRectangleRec(fullscreenButton,PINK);
        DrawTexture(Start_Button,backgroundWidth/2,backgroundHeight/2,WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), fullscreenButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            menuStateSelected=1;
        }
    }
    else if(menuStateSelected == 1){
        drawing(fb,fb_flap);
        collision();
        birdJump();
        update_hb();
        pipe_movement(pill1,pill2);
        // if(CheckCollisionPointRec(GetMousePosition(), fullscreenButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        //     menuStateSelected++;
        
    }
    else if(menuStateSelected == 2){
        DrawText( "Controls", 0, 0 ,20 ,BLACK );
        // if(CheckCollisionPointRec(GetMousePosition(), fullscreenButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        //     menuStateSelected++;
    }
    else if(menuStateSelected == 3)
        CloseWindow();
    
}