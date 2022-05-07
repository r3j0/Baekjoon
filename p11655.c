//11655. ROT13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ROT13(char ch) {
	if (ch >= 65 && ch <= 90)
		return ((ch - 65 + 13) % 26 + 65);
	else if (ch >= 97 && ch <= 122)
		return ((ch - 97 + 13) % 26 + 97);
	else
		return ch;
}

int main(void) {
	char str[102];
	gets(str);
	for (int i = 0; i < strlen(str); i++) {
		str[i] = ROT13(str[i]);
		printf("%c", str[i]);
	}
	return 0;
}