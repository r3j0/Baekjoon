#include <stdio.h>

int numCount(int n) {
	int cnt = 0;
	while (n != 0) {
		cnt += n % 10;
		n /= 10;
	}
	return cnt;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		if (i + numCount(i) == n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}