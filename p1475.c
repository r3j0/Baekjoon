#include <stdio.h>

int main(void) {
	int set[10][10] = {0,};
	int max_set = 0;

	int num;
	scanf("%d", &num);
	if (num == 0)
		printf("1");
	else {
		while (num != 0) {
			int focus = num % 10;
			int i = 0;
			int conv = 0;
			while (set[i][focus] != 0) {
				if (focus == 9 && set[i][6] == 0) {
					conv = 1;
					break;
				}
				else if (focus == 6 && set[i][9] == 0) {
					conv = 2;
					break;
				}
				i++;
			}
			if (conv == 1)
				set[i][6] = 1;
			else if (conv == 2)
				set[i][9] = 1;
			else
				set[i][focus] = 1;
			if (i > max_set)
				max_set = i;
			num /= 10;
		}
		printf("%d", max_set+1);
	}
	return 0;
}