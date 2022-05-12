//2609. 최대공약수와 최소공배수
#include <stdio.h>

int main(void) {
	int a, b;
	int y = 1, v, p = 1;
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= (a > b ? b : a); i++) {
		if (a % i == 0) {
			if (b % i == 0) {
				y = i;
			}
		}
	}
	while (1) {
		if ((a * p) % b == 0) {
			v = a * p;
			break;
		}
		p++;
	}
	printf("%d %d", y, v);
	return 0;
}