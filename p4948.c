//4948. 베르트랑 공준
#include <stdio.h>
#define MAX 246913

int arr[MAX] = { 0, };

void arrChae(void) {
	for (int i = 2; i < MAX; i++) {
		for (int j = 2; j * i < MAX; j++) {
			arr[i * j] = 1;
		}
	}
}

int main(void) {
	int n;
	int cnt;
	arrChae();
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}