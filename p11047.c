#include <stdio.h>

int main(void) {
	int n, k;
	int price[10];
	int cnt = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &price[i]);
	}

	int focus = n - 1;
	while (focus >= 0) {
		if (price[focus] <= k) {
			cnt += k / price[focus];
			k %= price[focus];
			if (k == 0)
				break;
		}
		focus--;
	}
	
	printf("%d", cnt);

	return 0;
}