// 10990 : 별 찍기 - 15
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - j - 1; i++) {
			printf(" ");
		}
		printf("*");
		int p = 0;
		for (p = 0; p < 2*j-1; p++) {
			printf(" ");
		}
		if (j > 0)
			printf("*");
		printf("\n");
	}
	return 0;
}