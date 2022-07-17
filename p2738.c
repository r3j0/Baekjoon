// 2738 : 행렬 덧셈
#include <stdio.h>

int main(void) {
    int n,m;
    int arr[100][100] = {0,};
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            scanf("%d",&tmp);
            arr[i][j] += tmp;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}