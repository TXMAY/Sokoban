#include "raylib.h"

int stage[9][9];
char move_key;
int chr_x, chr_y;
int stage_cls = 0;
int stone;
void stage_print(void)
// 0은 공백, 1은 플레이어, 2은 벽, 3는 상자, 4은 벽, 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
        {
            if (stage[i][j] == 0)
            
            else if (stage[i][j] == 1)
            
            else if (stage[i][j] == 2)
            
            else
			printf("%c", stage[i][j]);
        }
	}
}
void stage_set(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 ; j++)
		{
			if (i == 0 || j == 0 || i == 9 || j == 9)
				stage[i][j] = 3;
			else
				stage[i][j] = 0;
		}
	}
	


}

void get_chr(void)
{
	stone = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (stage[i][j] == '0')
			{
				chr_x = i;
				chr_y = j;
				stage[i][j] = ' ';
			}
			if (stage[i][j] == '-')
			{
				stone++;
			}
		}
	}
}
void move(void)
{
	int x = 0, y = 0;
	switch (move_key)
	{
	case 'w':
		x = -1;
		break;
	case 'a':
		y = -1;
		break;
	case 's':
		x = 1;
		break;
	case 'd':
		y = 1;
		break;
	default:
		break;
	}
	if (stage[chr_x + x][chr_y + y] == '#' || stage[chr_x + x][chr_y + y] == '-')
	{
		stage[chr_x][chr_y] = '0';
	}
	else if (stage[chr_x + x][chr_y + y] == '+')
	{
		if (stage[chr_x + x * 2][chr_y + y * 2] == '-')
		{
			stage[chr_x + x * 2][chr_y + y * 2] = '+';
			stage[chr_x + x][chr_y + y] = '0';
		}
		else if (stage[chr_x + x * 2][chr_y + y * 2] == ' ')
		{
			stage[chr_x + x * 2][chr_y + y * 2] = '+';
			stage[chr_x + x][chr_y + y] = '0';
		}
		else if (stage[chr_x + x * 2][chr_y + y * 2] == '#' || stage[chr_x + x * 2][chr_y + y * 2] == '+')
		{
			stage[chr_x + x][chr_y + y] = '+';
			stage[chr_x][chr_y] = '0';
		}
	}
	else
	{
		stage[chr_x + x][chr_y + y] = '0';
	}
}

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "SoKoban");
	stage_set();
	while (stage_cls == 0)
	{
		stage_print();

		get_chr();
		get_move();
		move();
		system("cls");
		if (stone == 0)
		{
			stage_cls++;
			printf("clear!");
		}
	}
}