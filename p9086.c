// 9086 : 문자열
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int t;
    char str[1000];
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++) {
        gets(str);
        printf("%c%c\n", str[0], str[strlen(str) - 1]);
    }
    return 0;
}