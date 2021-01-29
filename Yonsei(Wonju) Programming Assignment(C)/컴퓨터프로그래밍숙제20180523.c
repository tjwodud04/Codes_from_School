#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define N 5

struct robotStruct
{
	int x, y;
	int score;
	int energy;
};

struct mapStruct
{
	char map[N][N];
	int tx, ty;
};

double distance;
double caldis(struct robotStruct a, struct mapStruct b);
void printmap(struct mapStruct b);

int main(void)
{
	struct robotStruct rs;
	struct mapStruct ms;

	char input;
	int i, j;
	int region[N][N];
	int random_value;

	rs.score = 0;
	int temp = 20;
	rs.energy = temp;

	srand(time(NULL));

	rs.x = (rand() % N) + 1;
	rs.y = (rand() % N) + 1;

	while (1)
	{
		ms.tx = (rand() % N) + 1;
		ms.ty = (rand() % N) + 1;
		if (rs.x != ms.tx || rs.y != ms.ty)
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
				ms.map[j][i] = '_';
			}
			else if (random_value <= 8)
			{
				region[j][i] = 2;
				ms.map[j][i] = '~';
			}
			else
			{
				region[j][i] = 3;
				ms.map[j][i] = '@';
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

	ms.map[rs.y - 1][rs.x - 1] = 'o';
	ms.map[ms.ty - 1][ms.tx - 1] = 'x';
	printmap(ms);

	printf("############################################################################ \n");
	printf("# 위치는 x = %d, y = %d ||| 보물과의 거리는 %f ||| 현재 에너지량 : %d  # \n", rs.x, rs.y, caldis(rs, ms), rs.energy);
	printf("############################################################################ \n");

	while (1)
	{

		printf("움직일 좌표 : \n");
		input = getch();
		printf("\n");

		if (input == 'a')
		{ //왼쪽으로 한 칸 움직입니다.
			if (rs.x == 1)
			{
				printf("");
			}

			else
			{
				if (rs.energy >= region[rs.y - 1][rs.x - 2])
				{
					rs.x--;

					if (!(rs.x == ms.tx && rs.y == ms.ty))
						rs.energy -= region[rs.y - 1][rs.x - 1];
				}
			}
		}

		if (input == 'd')
		{ //오른쪽으로 한 칸 움직입니다.
			if (rs.x == N)
			{
				printf("");
			}

			else
			{
				if (rs.energy >= region[rs.y - 1][rs.x])
				{
					rs.x++;

					if (!(rs.x == ms.tx && rs.y == ms.ty))
						rs.energy -= region[rs.y - 1][rs.x - 1];
				}
			}
		}

		if (input == 'w')
		{ //위쪽으로 한 칸 움직입니다.
			if (rs.y == 1)
			{
				printf("");
			}

			else
			{
				if (rs.energy >= region[rs.y - 2][rs.x - 1])
				{
					rs.y--;

					if (!(rs.x == ms.tx && rs.y == ms.ty))
						rs.energy -= region[rs.y - 1][rs.x - 1];
				}
			}
		}

		if (input == 's')
		{ //아래 쪽으로 한 칸 움직입니다.
			if (rs.y == N)
			{
				printf("");
			}

			else
			{
				if (rs.energy >= region[rs.y][rs.x - 1])
				{
					rs.y++;

					if (!(rs.x == ms.tx && rs.y == ms.ty))
						rs.energy -= region[rs.y - 1][rs.x - 1];
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
						ms.map[j][i] = '_';
					}
					else if (region[j][i] == 2)
					{
						ms.map[j][i] = '~';
					}
					else
					{
						ms.map[j][i] = '@';
					}
				}
			}

			ms.map[rs.y - 1][rs.x - 1] = 'o';
			ms.map[ms.ty - 1][ms.tx - 1] = 'x';

			printmap(ms);
		}

		if (input == 'x')
			break;

		printf("############################################################################ \n");
		printf("# 위치는 x = %d, y = %d ||| 보물과의 거리는 %f ||| 현재 에너지량 : %d   # \n", rs.x, rs.y, caldis(rs, ms), rs.energy);
		printf("############################################################################ \n");

		if (rs.x == ms.tx && rs.y == ms.ty)
		{
			system("cls");
			printf("##################################### \n");
			printf("# 축하합니다. 보물을 찾으셨습니다.  # \n");
			rs.score++;
			printf("#            score : %d              # \n", rs.score);
			printf("##################################### \n");

			temp--;

			if (temp == 0)
			{
				printf("Win! 최종 점수 : %d \n", rs.score);
				break;
			}

			rs.energy = temp;

			while (1)
			{
				ms.tx = (rand() % N) + 1;
				ms.ty = (rand() % N) + 1;

				if (rs.x != ms.tx || rs.y != ms.ty)
				{
					break;
				}
			}
			Sleep(1500);
			system("cls");

			ms.map[rs.y - 1][rs.x - 1] = 'o';
			ms.map[ms.ty - 1][ms.tx - 1] = 'x';

			printmap(ms);
			printf("############################################################################ \n");
			printf("# 위치는 x = %d, y = %d ||| 보물과의 거리는 %f ||| 현재 에너지량 : %d   # \n", rs.x, rs.y, caldis(rs, ms), rs.energy);
			printf("############################################################################ \n");
		}

		else if (rs.energy == 0)
		{
			system("cls");
			printf("##################################### \n");
			printf("#     Game over! 최종 점수 : %d      # \n", rs.score);
			printf("##################################### \n");
			break;
		}
	}

	printf("게임 종료 \n");

	system("pause");

	return 0;
}

double caldis(struct robotStruct a, struct mapStruct b)
{
	double distance;
	distance = sqrt(((a.x - b.tx) * (a.x - b.tx)) + ((a.y - b.ty) * (a.y - b.ty)));
	return distance;
}

void printmap(struct mapStruct b)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%c ", b.map[i][j]);
			//printf("%c ", tearray[i][j]);
		}
		printf("\n");
	}
	return;
}
