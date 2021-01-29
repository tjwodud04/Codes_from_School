#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

void main(void)
{
	char name[100];
	int score;
	int i;
	//int j;
	//int temp;
	int bestScore[5] = {100, 70, 50, 30, 20};
	char bestScoreName[5][100] = {"Lim", "Lee", "Park", "Kim", "James"};
	int rank[5];
	int next;
	for (int i = 0; i < 5; i++)
	{
		next = 0;
		for (int j = 0; j < 5; j++)
		{
			if (bestScore[i] < bestScore[j])
			{
				next++;
			}
		}
		rank[i] = next + 1;
	}
	for (i = 0; i < 5; i++)
		printf("%2d %10s %10d \n\n", rank[i], bestScoreName[i], bestScore[i]);

	while (1)
	{

		printf("이름 : ");
		scanf_s("%s", name, 100);
		if (!strcmp(name, "quit"))
		{
			printf("프로그램 종료 \n");
			break;
		}
		printf("점수 : ");
		scanf_s("%d", &score);
		if (score > 100)
		{
			printf("점수가 100점을 넘었습니다");
			break;
		}
		printf("이름 : %s  점수 : %d \n\n", name, score);
		//for문 활용해서 index 찾기
		//int max = bestScore[0];
		int index;

		for (i = 0; i < 5; i++)
		{
			if (score > bestScore[i])
			{
				index = i;
				break;
			}
		}
		//밀어내기
		for (i = 3; i >= index; i--)
		{
			bestScore[i + 1] = bestScore[i];
			strcpy_s(bestScoreName[i + 1], 100, bestScoreName[i]);
		}

		bestScore[index] = score;
		strcpy_s(bestScoreName[index], 100, name);

		/*
		if (score > bestScore[1] && score < bestScore[0]) {
			bestScore[1] = score;
		}
		else if (score > bestScore[2] && score < bestScore[1]) {
			bestScore[2] = score;
		}
		else if (score > bestScore[3] && score < bestScore[2]) {
			bestScore[3] = score;
		}
		else if (score > bestScore[4] && score < bestScore[3]) {
			bestScore[4] = score;
		}
		*/

		/*for (i = 0; i < 5; i++) {
				if (bestScore[i] < score) {
					temp = bestScore[i];
					bestScore[i] = score;
					score = temp;
				}
		}*/

		/*if (score > 70) {
			strcpy_s(bestScoreName[4], 100, bestScoreName[3]);
			bestScore[4] = bestScore[3];
			strcpy_s(bestScoreName[3], 100, bestScoreName[2]);
			bestScore[3] = bestScore[2];
			strcpy_s(bestScoreName[2], 100, bestScoreName[1]);
			bestScore[2] = bestScore[1];
			strcpy_s(bestScoreName[1], 100, name);
		}

		if (score < 70 && score > 50) {
			strcpy_s(bestScoreName[4], 100, bestScoreName[3]);
			bestScore[4] = bestScore[3];
			strcpy_s(bestScoreName[3], 100, bestScoreName[2]);
			bestScore[3] = bestScore[2];
			strcpy_s(bestScoreName[2], 100, name);
			bestScore[2] = score;
		}

		if (score < 50 && score > 30) {
			strcpy_s(bestScoreName[4], 100, bestScoreName[3]);
			bestScore[4] = bestScore[3];
			strcpy_s(bestScoreName[3], 100, name);
			bestScore[3] = score;
		}

		if (score < 30 && score > 20) {
			strcpy_s(bestScoreName[4], 100, name);
			bestScore[4] = score;
		}*/

		for (i = 0; i < 5; i++)
			printf("%2d %10s %10d \n\n", rank[i], bestScoreName[i], bestScore[i]);
	}
	system("pause");

	return 0;
}