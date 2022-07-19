// 23825 : SASA 모형을 만들어보자
#include <stdio.h>

int main(void) {
    int a,b,min;
    scanf("%d %d",&a,&b);
    if(a<b)
        min = a;
    else
        min = b;
    printf("%d",min/2);
    return 0;
}