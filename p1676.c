//1676. 팩토리얼 0의 개수
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int a = 1, b = 1, c = 1;
	while (a * 5 <= n)
		a++;
	a--;
	while (b * 25 <= n)
		b++;
	b--;
	while (c * 125 <= n)
		c++;
	c--;
	printf("%d", a + b + c);
	return 0;
}