#include <stdio.h>
#include <Windows.h>

main(void)
{
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = 5; i > 0; i--)
	{
		for (j = 0; j < 7 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	system("pause");
}