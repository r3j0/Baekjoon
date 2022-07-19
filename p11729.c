// 11729 : 하노이 탑 이동 순서
#include <stdio.h>
void hanoi(int from, int to, int n) {
    if (n == 1) {
        printf("%d %d\n", from, to);
        return;
    }
    int empty = 6 - from - to;
    hanoi(from, empty, n - 1);
    printf("%d %d\n", from, to);
    hanoi(empty, to, n - 1);
}

int count = 0;

void pow(int n, int i, int p) {
    if (i == p) {
        count += n;
    }
    else {
        pow(n*2, i+1, p);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        pow(1, 0, i);
    }
    printf("%d\n",count);
    hanoi(1, 3, n);
    return 0;
}