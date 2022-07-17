// 2754 : 학점계산
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char str[3];
    scanf("%s",str);
    if(!(strcmp(str,"A+")))
        printf("4.3");
    else if(!(strcmp(str,"A0")))
        printf("4.0");
    else if(!(strcmp(str,"A-")))
        printf("3.7");
    else if(!(strcmp(str,"B+")))
        printf("3.3");
    else if(!(strcmp(str,"B0")))
        printf("3.0");
    else if(!(strcmp(str,"B-")))
        printf("2.7");
    else if(!(strcmp(str,"C+")))
        printf("2.3");
    else if(!(strcmp(str,"C0")))
        printf("2.0");
    else if(!(strcmp(str,"C-")))
        printf("1.7");
    else if(!(strcmp(str,"D+")))
        printf("1.3");
    else if(!(strcmp(str,"D0")))
        printf("1.0");
    else if(!(strcmp(str,"D-")))
        printf("0.7");
    else if(!(strcmp(str,"F")))
        printf("0.0");
    return 0;
}