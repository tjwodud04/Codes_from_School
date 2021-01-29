#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define N 5

double distance;
double caldis(int x, int y, int tx, int ty);
void printmap(char map[N][N]);

int main(void)
{
	int tx, ty, x, y;
	char input, map[N][N];
	int score, energy, i, j;
	int region[N][N];
	int random_value;
	score = 0;
	int temp = 20;
	energy = temp;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;

	while (1)
	{
		tx = (rand() % N) + 1;
		ty = (rand() % N) + 1;
		if (x != tx || y != ty)
		{
			break;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			random_value = rand() % 11;
			if (random_value < 5)
			{
				region[j][i] = 1;
				map[j][i] = '_';
			}
			else if (random_value <= 8)
			{
				region[j][i] = 2;
				map[j][i] = '~';
			}
			else
			{
				region[j][i] = 3;
				map[j][i] = '@';
			}
		}
	}

	/*for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			random_value = rand() % 11;

			if (random_value < 5) {
				region[i][j] = 95;
				printf("%c ", 95);
			}
			else if (random_value < 8) {
				region[i][j] = 126;
				printf("%c ", 126);
			}
			else {
				region[i][j] = 64;
				printf("%c ", 64);
			}
			//printf("%c %c %c", 95, 126, 64);
		}
		printf("\n");
	}*/

	map[y - 1][x - 1] = 'o';
	map[ty - 1][tx - 1] = 'x';
	printmap(map);

	printf("############################################################################ \n");
	printf("# ��ġ�� x = %d, y = %d ||| �������� �Ÿ��� %f ||| ���� �������� : %d  # \n", x, y, caldis(x, y, tx, ty), energy);
	printf("############################################################################ \n");

	while (1)
	{

		printf("������ ��ǥ : \n");
		input = getch();
		printf("\n");

		if (input == 'a')
		{ //�������� �� ĭ �����Դϴ�.
			if (x == 1)
			{
				printf("");
			}

			else
			{
				if (energy >= region[y - 1][x - 2])
				{
					x--;

					if (!(x == tx && y == ty))
						energy -= region[y - 1][x - 1];
				}
			}
		}

		if (input == 'd')
		{ //���������� �� ĭ �����Դϴ�.
			if (x == N)
			{
				printf("");
			}

			else
			{
				if (energy >= region[y - 1][x])
				{
					x++;

					if (!(x == tx && y == ty))
						energy -= region[y - 1][x - 1];
				}
			}
		}

		if (input == 'w')
		{ //�������� �� ĭ �����Դϴ�.
			if (y == 1)
			{
				printf("");
			}

			else
			{
				if (energy >= region[y - 2][x - 1])
				{
					y--;

					if (!(x == tx && y == ty))
						energy -= region[y - 1][x - 1];
				}
			}
		}

		if (input == 's')
		{ //�Ʒ� ������ �� ĭ �����Դϴ�.
			if (y == N)
			{
				printf("");
			}

			else
			{
				if (energy >= region[y][x - 1])
				{
					y++;

					if (!(x == tx && y == ty))
						energy -= region[y - 1][x - 1];
				}
			}
		}

		if (input == 'a' || 'd' || 'w' || 's')
		{
			system("cls");
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{

					if (region[j][i] == 1)
					{
						map[j][i] = '_';
					}
					else if (region[j][i] == 2)
					{
						map[j][i] = '~';
					}
					else
					{
						map[j][i] = '@';
					}
				}
			}

			map[y - 1][x - 1] = 'o';
			map[ty - 1][tx - 1] = 'x';

			printmap(map);
		}

		if (input == 'x')
			break;

		printf("############################################################################ \n");
		printf("# 위치는 x = %d, y = %d ||| 보물과의 거리는 %f ||| 현재 에너지량 : %d   # \n", x, y, caldis(x, y, tx, ty), energy);
		printf("############################################################################ \n");

		if (x == tx && y == ty)
		{
			system("cls");
			printf("##################################### \n");
			printf("# 축하합니다. 보물을 찾으셨습니다.  # \n");
			score++;
			printf("#            score : %d              # \n", score);
			printf("##################################### \n");

			temp--;

			if (temp == 0)
			{
				printf("Win! 최종 점수 : %d \n", score);
				break;
			}

			energy = temp;

			while (1)
			{
				tx = (rand() % N) + 1;
				ty = (rand() % N) + 1;

				if (x != tx || y != ty)
				{
					break;
				}
			}
			Sleep(1500);
			system("cls");

			map[y - 1][x - 1] = 'o';
			map[ty - 1][tx - 1] = 'x';

			printmap(map);
			printf("############################################################################ \n");
			printf("# 위치는 x = %d, y = %d ||| 보물과의 거리는 %f ||| 현재 에너지량 : %d   # \n", x, y, caldis(x, y, tx, ty), energy);
			printf("############################################################################ \n");
		}

		else if (energy == 0)
		{
			system("cls");
			printf("##################################### \n");
			printf("#     Game over! 최종 점수 : %d      # \n", score);
			printf("##################################### \n");
			break;
		}
	}

	printf("게임 종료 \n");

	system("pause");

	return 0;
}

double caldis(int x, int y, int tx, int ty)
{
	double distance;
	distance = sqrt(((x - tx) * (x - tx)) + ((y - ty) * (y - ty)));
	return distance;
}

void printmap(char map[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%c ", map[i][j]);
			//printf("%c ", temparray[i][j]);
		}
		printf("\n");
	}
	return;
}
