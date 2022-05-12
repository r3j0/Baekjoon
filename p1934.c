//1934. 최소공배수
#include <stdio.h>

int main(void) {
	int t;
	int a, b;
	int count = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		count = 1;
		while ((a * count) % b != 0) {
			count++;
		}
		printf("%d\n", a * count);
	}
	return 0;
}