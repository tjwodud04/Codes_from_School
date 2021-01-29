#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define N 5

int main(void)
{

	int x, y;
	double a;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;
	printf("좌표는 x = %d, y = %d \n", x, y);

	a = sqrt((pow(x - 1), 2) + (pow(y - 1), 2));
	printf("직선거리 a = %f \n", a);

	// return 0;
}

int main(void)
{
	int x, y;

	srand(time(NULL));

	x = (rand() % N) + 1;
	y = (rand() % N) + 1;

	printf("좌표는 x = %d, y = %d \n", x, y);

	// for
	// 	return 0;
}