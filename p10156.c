// 10156 : 과자
#include <stdio.h>

int main(void) {
int a,b,c;
scanf("%d %d %d",&a,&b,&c);
int res = a*b-c;
if(res < 0)
    res = 0;
printf("%d",res);
return 0;}