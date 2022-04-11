#include <stdio.h>
#include <string.h>

char str_buf[51];

int main(void) {
    int a;
    scanf("%d ", &a);
    for (int i = 0; i < a; i++) {
        scanf("%s", str_buf);
        int fp = 0;
        int result = 0;
        for (int j = 0; j < strlen(str_buf); j++) {
            if (str_buf[j] == '(')
                fp += 1;
            else if (str_buf[j] == ')')
                fp -= 1;

            if (fp < 0) {
                result = 1;
                break;
            }
        }

        if (fp == 0)
            result = 0;
        else
            result = 1;

        if (result == 0)
            printf("YES\n");
        else if (result == 1)
            printf("NO\n");
    }

    return 0;
}