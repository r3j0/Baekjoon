// 2920 : 음계
#include <stdio.h>

int main(void) {
	int a[8];
	int res = 1;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &a[i]);
		if (i == 0) {
			if (a[i] == 1) {
				res = 1;
			}
			else if (a[i] == 8) {
				res = 2;
			}
			else {
				res = 3;
			}
		}
		else {
			if (res == 1) {
				if (i + 1 == a[i]) {
					res = 1;
				}
				else {
					res = 3;
				}
			}
			else if (res == 2) {
				if (8 - i == a[i]) {
					res = 2;
				}
				else {
					res = 3;
				}
			}
		}
	}
	if (res == 1)
		printf("ascending");
	else if (res == 2)
		printf("descending");
	else
		printf("mixed");
	return 0;
}