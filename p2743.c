//2743. 단어 길이 재기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[102];
    scanf("%s",str);
    printf("%d",strlen(str));
    return 0;
}

/*

#include <stdio.h>

int main(void) {
    int count = 0;
    char ch = 'a';
    while(1) {
        scanf("%c",&ch);
        if(ch == '\0' || ch =='\n' || ch == EOF)
            break;
        count++;
    }
    printf("%d",count);
    return 0;
}

*/