// 1259 : 팰린드롬수
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[10];
	char comp[5];
	while (1) {
		int no = 0;
		scanf("%s", str);
		if (!strcmp(str, "0"))
			break;
		int size = strlen(str);
		if (size % 2 == 0) {
			int halfsize = size / 2;
			for (int i = 0; i < halfsize; i++)
				comp[i] = str[i];

			int fc = halfsize - 1;
			for (int i = halfsize; i < size; i++) {
				if (str[i] != comp[fc--])
					no = 1;
			}
		}
		else {
			int halfsize = size / 2;
			for (int i = 0; i < halfsize; i++)
				comp[i] = str[i];
			int fc = halfsize - 1;
			for (int i = halfsize + 1; i < size; i++) {
				if (str[i] != comp[fc--]) {
					no = 1;
				}
			}
		}
		if (no == 1)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}