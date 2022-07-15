// 6749 : Next in line
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", b + (b - a));
	return 0;
}
