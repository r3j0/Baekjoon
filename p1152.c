// 1152 : 단어의 개수
#include <stdio.h>

int main(void) {
	char ch;
	int record = 0;
	int count = 0;
	while (1) {
		ch = getchar();
		if (ch == ' ') {
			if (record == 1) {
				count++;
				record = 0;
			}
		}
		else if (ch == '\n') {
			break;
		}
		else {
			record = 1;
		}
	}
	if (record == 1) {
		count++;
		record = 0;
	}
	printf("%d", count);
	return 0;
}