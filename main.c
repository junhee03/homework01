#include <stdio.h>
#include <stdbool.h>
#include "screen.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
		clock_t SJTstart;
		SJTstart = clock();

		int i = 0;

		while (i < 5)
		{

			COORD pos = { 0,0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

			printf("Loding : ");

			int j = 0;
			while (j < i)
			{
				printf(".");
				j = j + 1;
			}
			Sleep(550);
			i = i + 1;

		}
		Sleep(500);
		system("cls");
		printf("실행 완료");
		Sleep(1000);

		clock_t SJTend;
		SJTend = clock();

	/*  width : 35    height : 12    가로 여백 : 7    세로여백 :5 */
	char screenBuf[35 * 12 + 1];
	int width = 34;
	int height = 12;
	int isGamePlaying = 1;

	int selectedIndex;

	#define SIZE 4 // 퍼즐의 크기

	int puzzle[SIZE][SIZE];

	// 빈 공간의 위치
	int emptyX, emptyY;


	while (isGamePlaying)
	{
		system("cls");
		clearBuffer(screenBuf, width, height);
		setTitleToScreenBuffer(screenBuf, width, height);
		printf("%s\ninput>", screenBuf);

		scanf_s("%d", &selectedIndex);

		system("cls");
		clearBuffer(screenBuf, width, height);

		switch (selectedIndex)
		{
		case 1:
			//setPlayingGameScreenBuffer(screenBuf, width, height);
			//printf("%s\ninput>", screenBuf);
			puzzleGame();
			break;
		case 2:
			setHowToPlayScreenBuffer(screenBuf, width, height);
			printf("%s\ninput>", screenBuf);
			break;
		case 3:
			setGameOverToScreenBuffer(screenBuf, width, height);
			printf("%s\ninput>", screenBuf);
			return 0;
		default:
			break;
		}

		printf("계속하려면 아무키나 누르세요");
		getchar();
		getchar();
	}

	return 0;
}
