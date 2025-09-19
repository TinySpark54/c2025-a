#include <stdio.h>
#include <stdlib.h>
static int step = 0;

void hanoi(int num,char source, char target, char through) {
    if (num == 1) {
        printf("    %c -> %c\n", source, target);
        step++;
    }
    else {
        hanoi(num - 1, source, through, target);
        printf("    %c -> %c\n", source, target);
        step++;
        hanoi(num - 1, through, source, target);
    }
    }

int main() {
    printf("请输入层数：");
    int num ;
    scanf_s("%d",&num);
    hanoi(num, 'A', 'B', 'C');
    printf("总步数：%d\n",step);
    system("pause");
    return 0;
}
