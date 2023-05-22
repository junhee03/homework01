#include <stdio.h>
#include "screen.h"

int main()
{
	/*  width : 35    height : 12    가로 여백 : 7    세로여백 :5 */
	char screenBuf[35 * 12 + 1];
	int width = 34;
	int height = 12;
	int isGamePlaying = 1;

	int selectedIndex;

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
		case 1 :
			setPlayingGameScreenBuffer(screenBuf, width, height);
			printf("%s\ninput>", screenBuf);
			break;
		case 2 :
			setHowToPlayScreenBuffer(screenBuf, width, height);
			printf("%s\ninput>", screenBuf);
			break;
		case 3 :
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