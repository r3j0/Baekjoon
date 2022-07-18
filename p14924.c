// 14924 : 폰 노이만과 파리
#include <stdio.h>

int main(void) {
	int s, t, d;
	scanf("%d %d %d", &s, &t, &d);
	t *= d / (s * 2);
	printf("%d", t);
	return 0;
}