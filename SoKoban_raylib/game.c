#include "raylib.h"

int stage[9][9];

int chr_x, chr_y;
int stage_cls = 0;
int stone;
    
// 0은 공백, 1은 플레이어, 2은 도착지, 3는 상자, 4은 벽, 

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
    stage[4][5] = 3;
    stage[2][3] = 2;
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
				chr_x = i;
				chr_y = j;
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
	
	
	if (stage[chr_x + x][chr_y + y] == 4 || stage[chr_x + x][chr_y + y] == 2)
	{
		stage[chr_x][chr_y] = 1;
	}
	else if (stage[chr_x + x][chr_y + y] == 3)
	{
		if (stage[chr_x + x * 2][chr_y + y * 2] == 2)
		{
			stage[chr_x + x * 2][chr_y + y * 2] = 3;
			stage[chr_x + x][chr_y + y] = 1;
		}
		else if (stage[chr_x + x * 2][chr_y + y * 2] == 0)
		{
			stage[chr_x + x * 2][chr_y + y * 2] = 3;
			stage[chr_x + x][chr_y + y] = 1;
		}
		else if (stage[chr_x + x * 2][chr_y + y * 2] == 4 || stage[chr_x + x * 2][chr_y + y * 2] == 3)
		{
			stage[chr_x + x][chr_y + y] = 3;
			stage[chr_x][chr_y] = 1;
		}
	}
	else
	{
		stage[chr_x + x][chr_y + y] = 1;
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
    Wave cat_wav = LoadWave("sounds/Cat_Walk.wav");
    Sound cat_walk = LoadSoundFromWave(cat_wav);
	stage_set();
	while (!WindowShouldClose())
	{
		BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{

                if (stage[i][j] == 0)
                    DrawText("null", 280.0f + 80.0f * i, 0.0f + 80.0f * j, 10, WHITE);
				else if (stage[i][j] == 1)
					DrawTexture(cat, 280.0f + 80.0f * i, 0.0f + 80.0f * j, WHITE);
				else if (stage[i][j] == 2)
					DrawTexture(box, 280.0f + 80.0f * i, 0.0f + 80.0f * j, WHITE);
				else if (stage[i][j] == 3)
					DrawTexture(wool, 280.0f + 80.0f * i, 0.0f + 80.0f * j, WHITE);
				else
					DrawTexture(wall, 280.0f + 80.0f * i, 0.0f + 80.0f * j, WHITE);
			}
		}
		get_chr();
		move();
        PlaySound(cat_walk);
		if (stone == 0)
		{
			stage_cls++;
			
		}
        
        EndDrawing();
	}
    UnloadTexture(cat);
    UnloadTexture(wall);
    UnloadTexture(box);
    UnloadTexture(wool);
    UnloadSound(cat_walk);
    UnloadWave(cat_wav);
    
    CloseAudioDevice();
    
    CloseWindow();

    return 0;
}