// 20499 : Darius님 한타 안 함?
#include <stdio.h>

int main(void) {
    int k, d, a;
    scanf("%d/%d/%d",&k,&d,&a);
    if(d == 0 || k+a<d)
        printf("hasu");
    else
        printf("gosu");
    return 0;
}