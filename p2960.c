// 2960 : 에라토스테네스의 채
#include <stdio.h>

int ch[1002] = { 0, };

int main(void) {
	int n, k;
	int cnt = 0;
	int done = 0;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) {
			if (ch[i*j] == 0) {
				cnt++;
				ch[i*j] = 1;
				//printf("%d지움\n", i * j);
			}
			if (cnt == k) {
				printf("%d\n", i*j);
				done = 1;
				break;
			}
		}
		if (done == 1)
			break;
	}
	return 0;
}