/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "윈도우 창 제목");              // (윈도우 창 너비, 윈도우 창 높이, 제목(char형 상수))

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second(프레임)



    while (!WindowShouldClose())    // Detect window close button or ESC key(WindowShouldClose: esc키를 누르거나 닫기 버튼을 눌렀는지 확인)
    {

        BeginDrawing();             // 드로잉 시작하도록 캔버스 설정

        ClearBackground(RAYWHITE);  // 배경색 설정

        DrawText("Hello World!", 190, 200, 20, LIGHTGRAY);                  // 텍스트 그리기(텍스트(char형 상수), X 좌표(int형), Y 좌표(int형), 폰트 크기(int형), 색깔)              

        EndDrawing();               // 캔버스 그리기 종료 및 스왑 버퍼(?)
    }


    CloseWindow();        // Close window and OpenGL context(창을 닫고 OpenGL(오픈 그래픽 라이브러리(그래픽스 표준 API 규격)) 컨텍스트(사전적: 맥락, 정보통신용어: 호출, 응답간의 환경정보)를 언로드함)

    return 0;
}