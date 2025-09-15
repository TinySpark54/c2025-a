#include <stdio.h>
#include <windows.h>

# define MAX 100

char list[MAX-1];

int main(void) {
    for (int i = 2; i < MAX; i++) {
        if (list[i-1]==0) {
            for (int j = i*i; j < MAX; j+=i) {
                list[j-1] = 1;
            }
        }

    }
    for (int i = 2; i < MAX; i++) {
        if (list[i-1]==0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
