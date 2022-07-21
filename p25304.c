// 25304 : 영수증
#include <stdio.h>

int main(void) {
    int num;
    int t;
    int a,b;
    scanf("%d",&num);
    scanf("%d",&t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d",&a,&b);
        num -= a*b;
    }
    if(num == 0)
        printf("Yes");
    else
        printf("No");
    return 0;
}