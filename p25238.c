// 25238 : 가희와 방어율 무시
#include <stdio.h>

int main(void) {
	int a, b;
	double d;
	scanf("%d %d", &a, &b);
	d = a * b;
	d /= 100;
	d = a - d;
	if (d < 100)
		printf("1");
	else
		printf("0");
}