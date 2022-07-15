// 2752 : 세수정렬
#include <stdio.h>

int main(void) {
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    for(int i = 0; i<3;i++) {
        for (int j = 0; j < 2; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                }
        }
        }
    for(int i = 0; i < 3; i++)
        printf("%d ",a[i]);
    return 0;
}