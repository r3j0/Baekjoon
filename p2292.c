#include <stdio.h>

int main(void) {
	int n;
	int cnt;
	scanf("%d", &n);
	if (n != 1) {
		int first = 2;
		int range = 5;
		cnt = 2;
		while (!(first <= n && first + range >= n)) {
			first += range + 1;
			range += 6;
			cnt++;
		}
	}
	else {
		cnt = 1;
	}
	printf("%d", cnt);
	return 0;
}
