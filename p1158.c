// 1158. 요세퍼스 문제
#include <stdio.h>

int main(void) {
    int n, k; //n : size
    int circle[5000]; // man
    int sequence[5000];
    int cursor = 0;
    int add; // 
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; i++)
        circle[i] = 1; // human exists

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            while (1) {
                cursor++;
                if (cursor > n - 1)
                    cursor = 0;
                if (circle[cursor] == 1)
                    break;
            }
        }
        sequence[i] = cursor+1;
        circle[cursor] = 0;
        while (1) {
            if (i == n - 1)
                break;
            cursor++;
            if (cursor > n - 1)
                cursor = 0;
            if (circle[cursor] == 1)
                break;
        }
    }

    printf("<");
    for (int i = 0; i < n; i++) {
        printf("%d",sequence[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf(">");
    return 0;
}