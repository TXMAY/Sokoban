#include "raylib.h"

int stage[9][9];

int chr_x, chr_y;
int stone;
  
// 0은 공백, 1은 플레이어, 2은 도착지, 3는 상자, 4은 벽, 5는 활성화된 상자

void stage_set(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 ; j++)
		{
			if (i == 0 || j == 0 || i == 8 || j == 8)
				stage[i][j] = 4;
			else
				stage[i][j] = 0;
		}
	}
    
    stage[4][4] = 1;
    stage[1][1]=stage[1][7]=stage[7][1]=stage[7][7] = 2;
    stage[2][4]=stage[5][2]=stage[7][4]=stage[4][6]=3;
    stage[1][2]=stage[1][6]=stage[2][6]=stage[3][2]=stage[3][3]=stage[3][6]=stage[5][5]=stage[6][1]=stage[6][2]=stage[6][5]=stage[6][6]=stage[6][7]=4;
}

void get_chr(void)
{
	stone = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (stage[i][j] == 1)
			{
				chr_x = j;
				chr_y = i;
				stage[i][j] = 0;
			}
			if (stage[i][j] == 2)
			{
				stone++;
			}
		}
	}
}
void move(void)
{
	int x = 0, y = 0;  
	
    if(IsKeyPressed(KEY_UP)) y = -1;
	if(IsKeyPressed(KEY_LEFT)) x = -1;
    if(IsKeyPressed(KEY_DOWN)) y = 1;
	if(IsKeyPressed(KEY_RIGHT)) x = 1;

	
	if (stage[chr_y + y][chr_x + x] == 4 || stage[chr_y + y][chr_x + x] == 2 || stage[chr_y + y][chr_x + x] == 5)
	{
		stage[chr_y][chr_x] = 1;
	}
	else if (stage[chr_y + y][chr_x + x] == 3)
	{
		if (stage[chr_y + y * 2][chr_x + x * 2] == 2)
		{
			stage[chr_y + y * 2][chr_x + x * 2] = 5;
			stage[chr_y + y][chr_x + x] = 1;
		}
		else if (stage[chr_y + y * 2][chr_x + x * 2] == 0)
		{
			stage[chr_y + y * 2][chr_x + x * 2] = 3;
			stage[chr_y + y][chr_x + x] = 1;
		}
		else if (stage[chr_y + y * 2][chr_x + x * 2] == 4 || stage[chr_y + y * 2][chr_x + x * 2] == 3)
		{
			stage[chr_y + y][chr_x + x] = 3;
			stage[chr_y][chr_x] = 1;
		}

	}
	else
	{
		stage[chr_y + y][chr_x + x] = 1;
	}
}
int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "SoKoban");
    InitAudioDevice();
	Texture2D cat = LoadTexture("images/cat.png");
	Texture2D wall = LoadTexture("images/wall.png");
	Texture2D wool = LoadTexture("images/wool.png");
    Texture2D box = LoadTexture("images/box.png");
    Texture2D box_wool = LoadTexture("images/box_wool.png");
    Sound cat_walk = LoadSound("sounds/Cat_Walk.wav");
    Music music = LoadMusicStream("sounds/Project_TIMIRUM_03.mp3");
    SetSoundVolume(cat_walk, 0.5);
    SetMusicVolume(music, 0.25);
    PlayMusicStream(music);
	stage_set();
	while (!WindowShouldClose())
	{
		BeginDrawing();
        
        UpdateMusicStream(music);
        
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{

                if (stage[i][j] == 0)
                    ;
				else if (stage[i][j] == 1)
					DrawTexture(cat, 280.0f + 80.0f * j, 0.0f + 80.0f * i, WHITE);
				else if (stage[i][j] == 2)
					DrawTexture(box, 280.0f + 80.0f * j, 0.0f + 80.0f * i, WHITE);
				else if (stage[i][j] == 3)
					DrawTexture(wool, 280.0f + 80.0f * j, 0.0f + 80.0f * i, WHITE);
				else if (stage[i][j] == 4)
					DrawTexture(wall, 280.0f + 80.0f * j, 0.0f + 80.0f * i, WHITE);
                else
                    DrawTexture(box_wool, 280.0f + 80.0f * j, 0.0f + 80.0f * i, WHITE);
			}
		}
		get_chr();
		move();
        if(IsKeyPressed(KEY_DOWN)||IsKeyPressed(KEY_LEFT)||IsKeyPressed(KEY_RIGHT)||IsKeyPressed(KEY_UP)) PlaySound(cat_walk);
        if(IsKeyPressed(KEY_R)) stage_set();
		if (stone == 0)
		{
			DrawText("Clear!", screenWidth/2-140, screenHeight/2-60, 100, BLACK);
			
		}
        
        EndDrawing();
	}
    UnloadTexture(cat);
    UnloadTexture(wall);
    UnloadTexture(box);
    UnloadTexture(wool);
    UnloadSound(cat_walk);
    UnloadMusicStream(music);
    
    CloseAudioDevice();
    
    CloseWindow();

    return 0;
}