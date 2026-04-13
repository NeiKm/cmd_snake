#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define MAP_WIDTH  40
#define MAP_HEIGHT 20

void print_status(int position[2], int dir[2]) {
    const char* direction = "none";

    if (dir[0] == -1 && dir[1] == 0) {
        direction = "left";
    }
    else if (dir[0] == 1 && dir[1] == 0) {
        direction = "right";
    }
    else if (dir[0] == 0 && dir[1] == -1) {
        direction = "up";
    }
    else if (dir[0] == 0 && dir[1] == 1) {
        direction = "down";
    }

    printf("x=%2d y=%2d direction: %s\n", position[0], position[1], direction);
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    int pos[2] = { MAP_WIDTH / 2, MAP_HEIGHT / 2 };
    int dir[2] = { 0, 0 };

    for (int i = 0; i < 100; i++) {
        printf("Nei_km edition ;)\nУправление: W A S D Выход: ESC\n          %d%%", i);
        Sleep(10);
        system("cls");
    }

    while (1) {

        if (GetAsyncKeyState('W')) { 
            dir[0] = 0; dir[1] = -1;
        }
        if (GetAsyncKeyState('S')) { 
            dir[0] = 0; dir[1] = 1;
        }
        if (GetAsyncKeyState('D')) { 
            dir[0] = 1; dir[1] = 0;
        }
        if (GetAsyncKeyState('A')) { 
            dir[0] = -1; dir[1] = 0;
        }
        if (GetAsyncKeyState(VK_ESCAPE)) {
            break;
        }

        if (dir[0] != 0 || dir[1] != 0) {
            pos[0] += dir[0];
            pos[1] += dir[1];
        }

        if (pos[0] >= MAP_WIDTH) {
            pos[0] = MAP_WIDTH - 1;
        }
        if (pos[0] < 0) {
            pos[0] = 0;
        }
        if (pos[1] >= MAP_HEIGHT) {
            pos[1] = MAP_HEIGHT - 1;
        }
        if (pos[1] < 0) {
            pos[1] = 0;
        }

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                map[y][x] = '_';
            }
        }

        map[pos[1]][pos[0]] = '@';

        system("cls");
        print_status(pos, dir);

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                printf("%c", map[y][x]);
            }
            printf("\n");
        }
        Sleep(100);
    }

    return 0;
}