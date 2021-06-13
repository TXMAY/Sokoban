#include "raylib.h"

    
int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "text");
    
    SetTargetFPS(60);
    
    char PressedKey;
    char pressed = NULL;
    
    while(!WindowShouldClose())
    {

            PressedKey = GetCharPressed();          
            
            if(PressedKey != NULL)                  
                pressed = PressedKey;

        
        BeginDrawing();
            
            ClearBackground(RAYWHITE);
                
                DrawText(TextFormat("You pressed : %c",pressed),190,200,20,LIGHTGRAY);     
            
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}