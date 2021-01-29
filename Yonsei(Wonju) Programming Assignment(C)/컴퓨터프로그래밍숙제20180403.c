#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#define N 5

double distance;
double caldis(int x, int y, int tx, int ty);

/* �Ÿ��� ���ϴ� ����
int main(void) {

	int x, y;
	double a;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;
	printf("좌표는 x = %d, y = %d \n", x, y);

	a = sqrt(((x - 1) * (x - 1)) + ((y - 1) * (y - 1)));
	printf("직선거리 a = %f \n", a);

	return 0;
}*/

int main(void)
{
	int tx, ty;
	int x, y;
	char input;
	char a, w, s, d;
	int score, energy, i;

	score = 0;
	int temp = 10;
	energy = temp;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;
	tx = (rand() % N) + 1;
	ty = (rand() % N) + 1;

	if (x == tx, y == ty)
	{
		tx = (rand() % N) + 1;
		ty = (rand() % N) + 1;
	}
	printf("좌표는 x = %d, y = %d 거리값 : %f \n", x, y, caldis(x, y, tx, ty));
	printf("현재 에너지량 : %d \n", energy);

	while (1)
	{
		printf("움직일 좌표 : \n");
		input = getch();
		printf("\n");

		if (input == 'a')
		{
			if (x > 1)
			{
				x--;
				printf("왼쪽으로 한 칸 움직입니다. \n");
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y, tx, ty));
				energy--;
				printf("현재 에너지량 : %d %d \n", energy);
				if (energy == 0)
				{
					printf("GAME OVER, total score : %d \n", score);
					system("pause");
					break;
				}
			}
			if (x == 1)
			{
				printf("움직일 수 없습니다. \n");
			}
		}
		if (input == 'd')
		{
			if (x < N)
			{
				x++;
				printf("오른쪽으로 한 칸 움직입니다. \n");
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y, tx, ty));
				energy--;
				printf("현재 에너지량 : %d \n", energy);
				if (energy == 0)
				{
					printf("GAME OVER, total score : %d \n", score);
					system("pause");
					break;
				}
			}
			if (x == N)
			{
				printf("움직일 수 없습니다. \n");
			}
		}
		if (input == 'w')
		{
			if (y > 1)
			{
				y--;
				printf("위쪽으로 한 칸 움직입니다. \n");
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y, tx, ty));
				energy--;
				printf("현재 에너지량 : %d \n", energy);
				if (energy == 0)
				{
					printf("GAME OVER, total score : %d \n", score);
					system("pause");
					break;
				}
			}
			if (y == 1)
			{
				printf("움직일 수 없습니다. \n");
			}
		}
		if (input == 's')
		{
			if (y < N)
			{
				y++;
				printf("아래쪽으로 한 칸 움직입니다. \n");
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y, tx, ty));
				energy--;
				printf("현재 에너지량 : %d \n", energy);
				if (energy == 0)
				{
					printf("GAME OVER, total score : %d \n", score);
					system("pause");
					break;
				}
			}
			if (y == N)
			{
				printf("움직일 수 없습니다.\n");
			}
		}
		for (i = 10; i > 0; i--)
		{
			energy == i;
			if (x == tx && y == ty)
			{
				printf("축하합니다. 보물을 찾으셨습니다. \n");
				score++;
				printf("score : %d \n", score);
				printf("다음 스테이지로 이동합니다. \n");
				system("pause");
				tx = (rand() % N) + 1;
				ty = (rand() % N) + 1;
				if (x == tx, y == ty)
				{
					tx = (rand() % N) + 1;
					ty = (rand() % N) + 1;
				}
				energy = --temp;

				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y, tx, ty));
				printf("현재 에너지량 : %d \n", energy);

				if (energy == 0)
				{
					printf("WIN, final score : %d \n", score);
				}
			}
		}
		//move down
		if (input == 'x')
			break;
	}

	printf("게임 종료 \n");
	return 0;
}

double caldis(int x, int y, int tx, int ty)
{
	double distance;
	distance = sqrt(((x - tx) * (x - tx)) + ((y - ty) * (y - ty)));
	return distance;
}