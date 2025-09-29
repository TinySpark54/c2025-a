#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define WIDTH  10
#define HEIGHT 10

#define BEGIN_X 0
#define BEGIN_Y 1
#define END_X 9
#define END_Y 8

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define player "+"

const char map[HEIGHT][WIDTH+1]={
    "0000000000",
    "   0     0",
    "0 00 000 0",
    "0  0 0   0",
    "0 00 0 0 0",
    "0    0 0 0",
    "00000  0 0",
    "0     0000",
    "00000     ",
    "0000000000"
};
void gotoxy(short X, short Y)
{
    printf(" ");
    COORD scrn;
    scrn.X = X; scrn.Y = Y;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, scrn);
    printf(player);
    SetConsoleCursorPosition(handle, scrn);
}



int main() {
    int x = BEGIN_X;
    int y = BEGIN_Y;
    int key;
    int color = 0xffff00;
    for(int i=0;i<HEIGHT;i++) {
        printf(map[i]);
        printf("\n");
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | color);
    gotoxy(BEGIN_X,BEGIN_Y);
    while(1) {
        if ( _getch() == 224){//如果有按键按下，则_kbhit()函数返回真
            key = _getch();//使用_getch()函数获取按下的键值
            switch (key) {
                case KEY_UP:
                    if (map[y-1][x] == ' ') {
                        y -= 1;
                    }
                    break;
                case KEY_DOWN:
                    if (map[y+1][x] == ' ') {
                        y += 1;
                    }
                    break;
                case KEY_LEFT:
                    if (map[y][x-1] == ' ') {
                        x -= 1;
                    }
                    break;
                case KEY_RIGHT:
                    if (map[y][x+1] == ' ') {
                        x += 1;
                    }
                    break;
                default:
                    break;
            }
            gotoxy(x,y);
            if (x == END_X && y == END_Y) {
                gotoxy(0,HEIGHT+1);
                //SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | 0x);
                printf("You win!");
                system("pause");
                return 0;
            }
            _sleep(50);
        }
    }
}