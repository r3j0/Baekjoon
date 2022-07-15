// 1012 : 유기농 배추
#include <stdio.h>
int arr[50][50] = { 0, };
int m, n, k;
void search(int x, int y) {
	arr[x][y] = 0;
	if (x > 0) {
		if (arr[x - 1][y] == 1) {
			search(x - 1, y);
		}
	}
	if (x < m - 1) {
		if (arr[x + 1][y] == 1) {
			search(x + 1, y);
		}
	}
	if (y > 0) {
		if (arr[x][y - 1] == 1) {
			search(x, y - 1);
		}
	}
	if (y < n - 1) {
		if (arr[x][y + 1] == 1) {
			search(x, y + 1);
		}
	}

}
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}

		int cnt = 0;
		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				if (arr[x][y] == 1) {
					search(x,y);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}