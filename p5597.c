// 5597 : 과제 안 내신 분..?
#include <stdio.h>

int main(void) {
    int arr[31] = {0,};
    for(int i = 0; i < 28; i++) {
        int tmp;
        scanf("%d",&tmp);
        arr[tmp] = 1;
    }
    for (int i = 1; i <=30; i++) {
        if(arr[i] == 0)
            printf("%d\n",i);
    }
    return 0;
}