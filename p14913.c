// 14913 : 등차수열에서 항 번호 찾기
#include <stdio.h>

int main(void) {
	int cnt = 0;
	int a, d, k;
	scanf("%d %d %d", &a, &d, &k);
	if ((k - a) % d != 0 || (k - a) / d < 0)
		printf("X");
	else
		printf("%d", (k - a) / d + 1);
	return 0;
}