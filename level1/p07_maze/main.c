#include <windows.h>
#include <stdio.h>
#define WIDTH  20
#define HEIGHT 10
#define BEGIN_X 1
#define BEGIN_Y 2
#define END_X 3
#define END_Y 4

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
void gotoxy(int X, int Y ,HANDLE handle)
{
    COORD scrn;

    scrn.X = X; scrn.Y = Y;
    SetConsoleCursorPosition(handle, scrn);
}

void COLOR_PRINT(const char* s, int color ,HANDLE handle)
{
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf(s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

int main() {
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=0;i<HEIGHT;i++) {
        printf(map[i]);
    }
    gotoxy(BEGIN_X,BEGIN_Y)
}