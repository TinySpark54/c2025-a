#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAXLEN 100
enum DIR{forward=0, backward};

int GetWidth(HWND hd,RECT rc,CONSOLE_FONT_INFOEX ft);


int main() {
    HWND handle = GetConsoleWindow();
    if (handle == NULL) {
        printf("GetConsoleWindow failed!\n");
        system("pause");
        return 1;
    }
    RECT rect;
    CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(font);

    char word[MAXLEN] = "\0";
    scanf("%s", word);

    char space[MAXLEN] = "\0";
    int len = strlen(word);
    int location  = 0;
    enum DIR direction = forward;
    int width = 0;

    while (1) {
        width = GetWidth(handle, rect,font);
        if (width==0) {
            return 1;
        }
        if (width <= len) {
            printf("The window is too narrow!");
            system("pause");
            return 1;
        }

        printf("%s%s", space,word);

        if (location + len >= width) {
            direction = backward;
        }
        else if (location == 0) {
            direction = forward;
        }
        switch (direction) {
            case 0:
                strcat(space, " ");
                break;
            case 1:
                space[strlen(space) - 1] = '\0';
        }
    }
    return 0;
}
int GetWidth(HWND hd,RECT rc,CONSOLE_FONT_INFOEX ft) {
    if (GetClientRect(hd, &rc)==0) {
        printf("GetClientRect failed!\n");
        system("pause");
        return 0;
    };
    GetCurrentConsoleFontEx(hd, FALSE, &ft);

    return (rc.right-rc.left)/ft.dwFontSize.X;
}