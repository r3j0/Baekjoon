// 7569 : 토마토
#include <stdio.h>

int arr[100][100][100] = {0,};
int queue[1000000][3] = { 0, };
int queue_size = 0;
int count = 0;
int m, n, h;

void search(int sero, int garo, int floor, int next_day, int now_count) {
	if (garo > 0) {
		if (arr[sero][garo - 1][floor] == 0) {
			arr[sero][garo - 1][floor] = 1;
			queue[queue_size][0] = sero;
			queue[queue_size][1] = garo - 1;
			queue[queue_size++][2] = floor;
		}
	}
	if (garo < m - 1) {
		if (arr[sero][garo + 1][floor] == 0) {
			arr[sero][garo + 1][floor] = 1;
			queue[queue_size][0] = sero;
			queue[queue_size][1] = garo + 1;
			queue[queue_size++][2] = floor;
		}
	}
	if (sero > 0) {
		if (arr[sero - 1][garo][floor] == 0) {
			arr[sero - 1][garo][floor] = 1;
			queue[queue_size][0] = sero - 1;
			queue[queue_size][1] = garo;
			queue[queue_size++][2] = floor;
		}
	}
	if (sero < n - 1) {
		if (arr[sero + 1][garo][floor] == 0) {
			arr[sero + 1][garo][floor] = 1;
			queue[queue_size][0] = sero + 1;
			queue[queue_size][1] = garo;
			queue[queue_size++][2] = floor;
		}
	}
	if (floor > 0) {
		if (arr[sero][garo][floor - 1] == 0) {
			arr[sero][garo][floor - 1] = 1;
			queue[queue_size][0] = sero;
			queue[queue_size][1] = garo;
			queue[queue_size++][2] = floor - 1;
		}
	}
	if (floor < h - 1) {
		if (arr[sero][garo][floor + 1] == 0) {
			arr[sero][garo][floor + 1] = 1;
			queue[queue_size][0] = sero;
			queue[queue_size][1] = garo;
			queue[queue_size++][2] = floor + 1;
		}
	}

	if (now_count == next_day - 1) {
		if (next_day != queue_size) {
			next_day = queue_size;
			count++;
			search(queue[now_count + 1][0], queue[now_count + 1][1], queue[now_count + 1][2], next_day, now_count + 1);
		}
	}
	else {
		search(queue[now_count+1][0], queue[now_count+1][1], queue[now_count + 1][2], next_day, now_count + 1);
	}
}

int main(void) {
	int isallmo = 0;
	scanf("%d %d %d", &m, &n, &h);
	for (int l = 0; l < h; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j][l]);
				if (arr[i][j][l] == 1) {
					queue[queue_size][0] = i;
					queue[queue_size][1] = j;
					queue[queue_size++][2] = l;
				}
				if (arr[i][j][l] == 1) {
					isallmo = 1;
				}
			}
		}
	}
	if (isallmo == 0) {
		printf("-1");
	}
	else {
		if (queue_size > 0) {
			search(queue[0][0], queue[0][1], queue[0][2], queue_size, 0);
			for (int l = 0; l < h; l++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (arr[i][j][l] == 0) {
							printf("-1");
							return 0;
						}
					}
				}
			}
			printf("%d", count);
		}
		else {
			printf("0");
		}
	}
	return 0;
}