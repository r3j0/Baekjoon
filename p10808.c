//10808. 알파벳 개수
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int abc[26] = {0,};
	char str[100];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
		abc[(int)str[i] - 97]++;
	for (int i = 0; i < 26; i++)
		printf("%d ", abc[i]);
	return 0;
}