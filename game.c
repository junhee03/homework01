#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // 퍼즐의 크기

int puzzle[SIZE][SIZE];

// 빈 공간의 위치
int emptyX, emptyY;

void initPuzzle() {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            puzzle[i][j] = num++;
        }
    }
    puzzle[SIZE - 1][SIZE - 1] = 0; // 빈 공간은 0으로 표시

    emptyX = SIZE - 1;
    emptyY = SIZE - 1;
}

void shufflePuzzle() {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int dir = rand() % 4;
        int newX = emptyX;
        int newY = emptyY;
        switch (dir) {
        case 0: // 위쪽
            newY--;
            break;
        case 1: // 아래쪽
            newY++;
            break;
        case 2: // 왼쪽
            newX--;
            break;
        case 3: // 오른쪽
            newX++;
            break;
        }

        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
            puzzle[emptyY][emptyX] = puzzle[newY][newX];
            puzzle[newY][newX] = 0;
            emptyX = newX;
            emptyY = newY;
        }
    }
}

void printPuzzle() {
    printf("=============\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == 0) {
                printf("|  ");
            }
            else {
                printf("|%2d", puzzle[i][j]);
            }
        }
        printf("|\n");
        printf("=============\n");
    }
}

bool checkSolved() {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == SIZE - 1 && j == SIZE - 1) {
                return true;
            }
            if (puzzle[i][j] != num++) {
                return false;
            }
        }
    }
    return true;
}

void move(int newX, int newY) {
    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
        if ((newX == emptyX && abs(newY - emptyY) == 1) || (newY == emptyY && abs(newX - emptyX) == 1)) {
            puzzle[emptyY][emptyX] = puzzle[newY][newX];
            puzzle[newY][newX] = 0;
            emptyX = newX;
            emptyY = newY;
        }
    }
}

bool isQuit = false;

void puzzleGame()
{
    initPuzzle();
    shufflePuzzle();

    while (!checkSolved()) {
        system("cls");
        printPuzzle();

        printf("어디로 이동하시겠습니까? (w: 위, a: 왼쪽, s: 아래, d: 오른쪽 q: 메인메뉴)\n");

        char input = getchar();
        //getchar(); // 버퍼 비우기

        int newX = emptyX;
        int newY = emptyY;

        switch (input) {
        case 'w':
            newY--;
            break;
        case 'a':
            newX--;
            break;
        case 's':
            newY++;
            break;
        case 'd':
            newX++;
            break;
        case 'q':
            isQuit = true;
            break;
        }

        move(newX, newY);

        if (isQuit)
        {
            break;
        }
    }

    if (isQuit)
    {
        printf("메인 메뉴로 돌아갑니다\n");
    }
    else
    {
        printf("축하합니다! 퍼즐을 모두 해결했습니다!\n");
    }
}
