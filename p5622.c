//5622. 다이얼
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char word[17];
	int cnt = 0;
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] >= 65 && word[i] < 68)
			cnt += 3;
		else if (word[i] >= 68 && word[i] < 71)
			cnt += 4;
		else if (word[i] >= 71 && word[i] < 74)
			cnt += 5;
		else if (word[i] >= 74 && word[i] < 77)
			cnt += 6;
		else if (word[i] >= 77 && word[i] < 80)
			cnt += 7;
		else if (word[i] >= 80 && word[i] < 84)
			cnt += 8;
		else if (word[i] >= 84 && word[i] < 87)
			cnt += 9;
		else if (word[i] >= 87 && word[i] <= 90)
			cnt += 10;
	}
	printf("%d", cnt);
	return 0;
}