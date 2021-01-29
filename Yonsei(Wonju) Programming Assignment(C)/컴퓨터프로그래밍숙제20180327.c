#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#define N 5

double distance;
double caldis(int x, int y);

/*int main(void) {

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

int main()
{

	int x, y;
	char input;
	char a, w, s, d;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;

	printf("좌표는 x = %d, y = %d \n", x, y);

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
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y));
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
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y));
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
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y));
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
				printf("좌표는 x = %d, y = %d / 거리값 : %f \n", x, y, caldis(x, y));
			}
			if (y == N)
			{
				printf("움직일 수 없습니다.\n");
			}
		}
		//move down
		if (input == 'x')
			break;
	}
	printf("프로그램 종료 \n");
	return 0;
}

double caldis(int x, int y)
{
	double distance;
	distance = sqrt(((x - 1) * (x - 1)) + ((y - 1) * (y - 1)));
	return distance;
}