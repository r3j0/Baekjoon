#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[20000];
int main(void) {
	int value[4] = { 0, }; // 1. lower, 2. upper, 3. digit, 4. blank
	while (1) {
		gets(str);
		if (str[0] == EOF || str[0] == '\0' || str[0] == '\n')
			break;
		for (int i = 0; i < strlen(str); i++) {
			if ((int)str[i] >= 65 && (int)str[i] <= 90) {
				value[1]++;
			}
			else if ((int)str[i] >= 97 && (int)str[i] <= 122) {
				value[0]++;
			}
			else if (str[i] == ' ') {
				value[3]++;
			}
			else {
				value[2]++;
			}
		}
		if (value[0] + value[1] + value[2] + value[3] == 0)
			break;
		for (int i = 0; i < 4; i++) {
			printf("%d", value[i]);
			value[i] = 0;
			if (i != 3) {
				printf(" ");
			}
		}
		str[0] = '\0';
		printf("\n");
	}
	return 0;
}