// 2744 : 대소문자 바꾸기
#include <stdio.h>

int main(void) {
    char str[100];
    int i = 0;
    scanf("%s",str);
    while(str[i]) {
    if(str[i] >= 65 && str[i] <= 90) {
        str[i] += 32;
    }
    else {
        str[i] -= 32;
    }
        i++;
    }
    printf("%s",str);
    return 0;
}