#include "raylib.h"
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second(프레임)



    while (!WindowShouldClose())    // Detect window close button or ESC key(WindowShouldClose: esc키를 누르거나 닫기 버튼을 눌렀는지 확인)
    {

        BeginDrawing();             // 드로잉 시작하도록 캔버스 설정

        ClearBackground(RAYWHITE);  // 배경색 설정
        DrawGrid(10, 5.0f);                                                          // Draw a grid (centered at (0, 0, 0))           

        EndDrawing();               // 캔버스 그리기 종료 및 스왑 버퍼(?)
    }


    CloseWindow();        // Close window and OpenGL context(창을 닫고 OpenGL(오픈 그래픽 라이브러리(그래픽스 표준 API 규격)) 컨텍스트(사전적: 맥락, 정보통신용어: 호출, 응답간의 환경정보)를 언로드함)

    return 0;
}