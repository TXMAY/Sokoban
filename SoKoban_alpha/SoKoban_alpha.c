#include <stdio.h>
#include <Windows.h>

char stage[5][5];
char move_key;
int chr_x, chr_y;
int stage_cls = 0;
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
	stage[2][3] = '0';
	stage[2][2] = '+';


}
void get_move(void)
{
	printf("움직일 방향을 입력하세요(w,a,s,d) :");
	scanf("%c", &move_key);
}
void get_chr(void)
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
			if (stage[i][j] == '0'|| stage[i][j] == '%')
			{
				chr_x = i;
				chr_y = j;
			}
	}
}
void stage_move(void)
{
	if (move_key == 'w')
	{
		if (stage[chr_x][chr_y] == '%' && stage[chr_x - 1][chr_y] == ' ')
		{
			stage[chr_x][chr_y] = '-';
			stage[chr_x - 1][chr_y] = '0';
		}
		if (stage[chr_x - 1][chr_y] == '-')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x - 1][chr_y] = '%';
		}
		if (stage[chr_x - 1][chr_y] == '+'&& stage[chr_x - 2][chr_y] != '#')
		{
			if (stage[chr_x - 2][chr_y] == '-')
			{
				stage[chr_x][chr_y] = ' ';
				stage[chr_x - 1][chr_y] = '0';
				stage[chr_x - 2][chr_y] = '*';
			}
			else if (stage[chr_x - 2][chr_y] != '+')
			{
				stage[chr_x][chr_y] = ' ';
				stage[chr_x - 1][chr_y] = '0';
				stage[chr_x - 2][chr_y] = '+';
			}
		}
		if (stage[chr_x-1][chr_y] != '#'&& stage[chr_x - 1][chr_y] == ' ')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x-1][chr_y] = '0';
		}
	}
	else if (move_key == 'a')
	{
		if (stage[chr_x][chr_y] == '%' && stage[chr_x][chr_y - 1] != '#')
		{
			stage[chr_x][chr_y] = '-';
			stage[chr_x][chr_y - 1] = '0';
		}
		if (stage[chr_x][chr_y - 1] == '-')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x][chr_y - 1] = '%';
		}
		if (stage[chr_x][chr_y - 1] == '+' && stage[chr_x][chr_y - 2] != '#')
		{
			if (stage[chr_x][chr_y - 2] == '-')
			{
				stage[chr_x][chr_y] = ' ';
				stage[chr_x][chr_y - 1] = '0';
				stage[chr_x][chr_y - 2] = '*';
			}
			else if(stage[chr_x][chr_y - 2] != '+')
			{
				stage[chr_x][chr_y] = ' ';
				stage[chr_x][chr_y - 1] = '0';
				stage[chr_x][chr_y - 2] = '+';
			}
		}
		if (stage[chr_x][chr_y - 1] != '#' && stage[chr_x][chr_y - 1] == ' ')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x][chr_y - 1] = '0';
		}
	}
	else if (move_key == 's')
	{
		if (stage[chr_x][chr_y] == '%' && stage[chr_x + 1][chr_y] == ' ')
		{
			stage[chr_x][chr_y] = '-';
			stage[chr_x + 1][chr_y] = '0';
		}
		if (stage[chr_x + 1][chr_y] == '-')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x + 1][chr_y] = '%';
		}
		if (stage[chr_x + 1][chr_y] == '+' && stage[chr_x + 2][chr_y] != '#')
		{
			if (stage[chr_x + 2][chr_y] == '-')
			{
				stage[chr_x][chr_y] = ' ';
				stage[chr_x + 1][chr_y] = '0';
				stage[chr_x + 2][chr_y] = '*';
			}
			else if (stage[chr_x + 1][chr_y] != '+')
			{
				stage[chr_x][chr_y] = ' ';
				stage[chr_x + 1][chr_y] = '0';
				stage[chr_x + 2][chr_y] = '+';
			}
		}
		if (stage[chr_x + 1][chr_y] != '#' && stage[chr_x + 1][chr_y] == ' ')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x + 1][chr_y] = '0';
		}
	}
	else if (move_key == 'd')
	{
	if (stage[chr_x][chr_y] == '%' && stage[chr_x][chr_y + 1] != '#')
	{
		stage[chr_x][chr_y] = '-';
		stage[chr_x][chr_y + 1] = '0';
	}
	if (stage[chr_x][chr_y + 1] == '-')
	{
		stage[chr_x][chr_y] = ' ';
		stage[chr_x][chr_y + 1] = '%';
	}
	if (stage[chr_x][chr_y + 1] == '+' && stage[chr_x][chr_y + 2] != '#')
	{
		if (stage[chr_x][chr_y + 2] == '-')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x][chr_y + 1] = '0';
			stage[chr_x][chr_y + 2] = '*';
		}
		else if (stage[chr_x][chr_y + 2] != '+')
		{
			stage[chr_x][chr_y] = ' ';
			stage[chr_x][chr_y + 1] = '0';
			stage[chr_x][chr_y + 2] = '+';
		}
	}
	if (stage[chr_x][chr_y + 1] != '#' && stage[chr_x][chr_y + 1] == ' ')
	{
		stage[chr_x][chr_y] = ' ';
		stage[chr_x][chr_y + 1] = '0';
	}
	}
}
int main(void)
{
	stage_set();
	while (stage_cls == 0)
	{
		stage_print();
		get_move();
		get_chr();
		stage_move();
		system("cls");
	}
}