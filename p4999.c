// 4999 : 아!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char a[1000]; 
    char b[1000];
    gets(a);
    gets(b);
    if(strlen(a) >= strlen(b)) {
        printf("go");
    }
    else {
        printf("no");
    }
    return 0;
}