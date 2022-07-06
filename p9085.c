#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++) {
        int m;
        int cnt = 0;
        int tmp = 0;
        scanf("%d",&m);
        for (int j = 0; j < m; j++) {
            scanf("%d",&tmp);
            cnt += tmp;
        }
        printf("%d\n",cnt);
    }
    return 0;
}