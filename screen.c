#include <string.h>
#include "screen.h"

int clearBuffer(char* screenBuf, int width, int height)
{
	int i = 0;	/* 가로 index */
	int j = 0;  /* 세로 index */
	while (j < height)
	{
		while (i < width + 1) /* 개행문자때문에 + 1*/
		{
			if (i == width)
				screenBuf[i + (j * (width + 1))] = '\n';
			else
			{
				if (i == 0 || i == 1 || i == (width - 1) || i == (width - 2) || j == 0 || j == (height - 1))
					screenBuf[i + (j * (width + 1))] = '#';
				else
					screenBuf[i + (j * (width + 1))] = ' ';
			}
			i = i + 1;
		}
		i = 0;
		j = j + 1;
	}
	screenBuf[height * (width + 1) - 1] = '\0';
}

/* 수업시간에 배운 x,y에 스트링을 쓰는 함수를 짜면 됨. */
int writeStringToBuffer(char* screenBuf, const char* string, int x, int y)
{
	memmove((screenBuf + x + y * 35), string, strlen(string));
}

/* 타이틀 화면 그리는 버퍼랑 게임오버, 게임설명 등등 이런식으로 만들면 보기 편하겠죠? */
int setTitleToScreenBuffer(char* screenBuf, int width, int height)
{
	writeStringToBuffer(screenBuf, "무단횡단 게임", 11, 3);
	writeStringToBuffer(screenBuf, "1. 게임 시작", 11, 5);
	writeStringToBuffer(screenBuf, "2. 게임 방법", 11, 6);
	writeStringToBuffer(screenBuf, "3. 게임 종료", 11, 7);
}
int setPlayingGameScreenBuffer(char* screenBuf, int width, int height)
{
	writeStringToBuffer(screenBuf, "게임 진행 화면입니다", 7, 5);
}

int setHowToPlayScreenBuffer(char* screenBuf, int width, int height)
{
	writeStringToBuffer(screenBuf, "게임 설명 화면입니다", 7, 3);
	writeStringToBuffer(screenBuf, "조작키 : w,a,s,d", 7, 5);
	writeStringToBuffer(screenBuf, "장애물을 피해", 7, 6);
	writeStringToBuffer(screenBuf, "앞으로 나아가세요!", 7, 7);
}

int setGameOverToScreenBuffer(char* screenBuf, int width, int height)
{
	writeStringToBuffer(screenBuf, "게임 종료 화면입니다", 8, 5);
	
}