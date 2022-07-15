// 2667 : 단지번호붙이기
#include <stdio.h>

int n;
int arr[25][25] = { 0, };
int res[625] = { 0, };

void search(int y, int x, int build) {
	arr[y][x] = 0;
	res[build] += 1;
	if (x > 0) {
		if (arr[y][x - 1] == 1) {
			search(y, x - 1, build);
		}
	}
	if (y > 0) {
		if (arr[y - 1][x] == 1) {
			search(y - 1, x, build);
		}
	}
	if (x < n - 1) {
		if (arr[y][x + 1] == 1) {
			search(y, x + 1, build);
		}
	}
	if (y < n - 1) {
		if (arr[y + 1][x] == 1) {
			search(y + 1, x, build);
		}
	}
}

int main(void) {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch = getchar();
			arr[i][j] = ch - '0';
		}
		getchar();
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				search(i, j, cnt);
				cnt++;
			}
		}
	}
	for (int i = 0; i < cnt - 1; i++) {
		int min = i;
		for (int j = i + 1; j < cnt; j++) {
			if (res[min] > res[j])
				min = j;
		}
		int tmp = res[min];
		res[min] = res[i];
		res[i] = tmp;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}