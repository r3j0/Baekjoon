// 17499 : 수열과 시프트 쿼리
#include <stdio.h>

int main(void) {
	int n, q;
	int arr[200000];
	int start = 0;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < q; i++) {
		int what = 0;
		scanf("%d", &what);
		if (what == 1) {
			int loc = 0;
			int value = 0;
			scanf("%d %d", &loc, &value);
			loc = (start + loc - 1) % n;
			arr[loc] += value;

			// 3에 넣으래 ( 인덱스 2에 넣으래 )
			// start는 4야 1에 넣어야해
			// start + loc - 1 % n 
		}
		else if (what == 2) {
			int value = 0;
			scanf("%d", &value);
			start -= value;
			while (start < 0) {
				start += n;
			}
		}
		else if (what == 3) {
			int value = 0;
			scanf("%d", &value);
			start += value;
			while (start >= n) {
				start -= n;
			}
		}
	}

	int cnt = 0;
	while (cnt < n) {
		printf("%d ", arr[start]);
		start++;
		if (start >= n)
			start -= n;
		cnt++;
	}
}