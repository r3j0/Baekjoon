#include <stdio.h>

int people[14][16] = {0,};

int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int k, n;
		int floor = 0;
		scanf("%d", &k);
		scanf("%d", &n);
		for (floor = 0; floor < k; floor++) {
			if (floor == 0) {
				for (int cell = 1; cell <= n; cell++)
					people[floor][cell] = cell;
			}
			else {
				for (int cell = 1; cell <= n; cell++) {
					int cnt = 0;
					for (int precell = 1; precell <= cell; precell++) {
						cnt += people[floor-1][precell];
					}
					people[floor][cell] = cnt;
				}
			}
		}
		int res = 0;
		for (int cell = 1; cell <= n; cell++)
			res += people[floor - 1][cell];
		printf("%d\n", res);
	}
	return 0;
}