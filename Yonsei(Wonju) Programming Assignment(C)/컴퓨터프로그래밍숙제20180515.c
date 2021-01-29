#include <stdio.h>

main(void)
{
	char robotName[5][100];
	int i, j, n;
	char temp[100];
	n = sizeof(robotName) / sizeof(char[100]);

	for (i = 0; i < 5; i++)
	{
		printf("로봇의 이름은: ");
		scanf_s("%s", robotName[i], 100);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s ", robotName[i]);
	}
	printf("\n");

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(robotName[j], robotName[j + 1]) > 0)
			{
				strcpy(temp, robotName[j]);
				strcpy(robotName[j], robotName[j + 1]);
				strcpy(robotName[j + 1], temp);
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s ", robotName[i]);
	}
	printf("\n");

	system("pause");
}