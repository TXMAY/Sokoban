#include <stdio.h>
#include <Windows.h>

char stage[5][5];
char move_key;
int chr_x, chr_y;
int stage_cls = 0;
int stone;
void stage_print(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%c", stage[i][j]);
		printf("\n");
	}
}
void stage_set(void)
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (i == 0 || j == 0 || i == 4 || j == 4)
				stage[i][j] = '#';
			else
				stage[i][j] = ' ';
		}
	}
	stage[1][1] = '-';
	stage[3][3] = '-';
	stage[2][1] = '+';
	stage[2][3] = '+';
	stage[2][2] = '0';


}
void get_move(void)
{
	printf("%d\n", stone);
	printf("움직일 방향을 입력하세요(w,a,s,d) :");
	scanf("%c", &move_key);

}
void get_chr(void)
{
	stone = 0;
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
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