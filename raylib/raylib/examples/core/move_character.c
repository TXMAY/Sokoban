#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "move character");
    
    Texture2D fox = LoadTexture("resources/fox.png");           // 2D 텍스쳐 로드, 파일에서 텍스쳐 로드(파일 기본 위치는 해당 예제가 있는 파일)
    
    Vector2 position = { (float)screenWidth/2, (float)screenHeight/2 };
    Rectangle frameRec = { 0.0f, 0.0f, (float)fox.width/6, (float)fox.height };     // Rectangle : 이미지(텍스쳐)의 직사각형 부분을 가져오기(정확한 설명은 모르겠음 앞에 두 좌표(0,0)와 뒤에 두 좌표(80,80)가 꼭짓점이고 그 꼭짓점을 대각선으로 사각형을 그리고 그 안에 이미지(텍스쳐)를 가져오는거 같음)
    int currentFrame = 0;
    
    int frameSpeed = 600;
    int framesCounter = 0;
    
    while(!WindowShouldClose())
    {    

        framesCounter++;
        
        if(IsKeyDown(KEY_RIGHT))
        {
            if(currentFrame < 3)
                currentFrame = 4;
                
            if(framesCounter >= frameSpeed)
            {
                framesCounter = 0;
                currentFrame++;
                
                if(currentFrame > 5)
                    currentFrame = 4;
                    
                frameRec.x = (float)currentFrame*(float)fox.width/6;
            }
        }
        else if(IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_UP)||IsKeyDown(KEY_DOWN))
        {
            if(currentFrame < 1)
                currentFrame = 2;
                
            if(framesCounter >= frameSpeed)
            {
                framesCounter = 0;
                currentFrame++;
                
                if(currentFrame > 3)
                    currentFrame = 2;
                    
                frameRec.x = (float)currentFrame*(float)fox.width/6;
            }
        }
        else 
        {
            if(currentFrame > 1)
                currentFrame = 0;
                
            if(framesCounter >= frameSpeed)
            {
                framesCounter = 0;
                currentFrame++;
                
                if(currentFrame > 1)
                    currentFrame = 0;
                    
                frameRec.x = (float)currentFrame*(float)fox.width/6;
            }
        }

        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            DrawTextureRec(fox, frameRec, position, WHITE);     // 직사각형으로 정의된 텍스쳐의 일부를 그림(Texture2D 텍스쳐, 직사각형 소스, Vector2 위치, 색깔)
            
            float spd = 0.025f;
            
            if (IsKeyDown(KEY_RIGHT)) position.x += spd;                           
            if (IsKeyDown(KEY_LEFT)) position.x -= spd;                            
            if (IsKeyDown(KEY_UP)) position.y -= spd;                              
            if (IsKeyDown(KEY_DOWN)) position.y += spd;  

        EndDrawing();
    }

    UnloadTexture(fox);

    CloseWindow();

    return 0;
}