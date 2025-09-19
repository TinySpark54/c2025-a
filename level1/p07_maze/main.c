#include <windows.h>
#include <stdio.h>
#define WIDTH  20
#define HEIGHT 10

const char map[HEIGHT][WIDTH+1]={
    "▨▩▧▤▥▣◀▶▲▼●　",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};
void gotoxy(int X, int Y)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = X; scrn.Y = Y;
    SetConsoleCursorPosition(hOuput, scrn);
}

void COLOR_PRINT(const char* s, int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf(s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}