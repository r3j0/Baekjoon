// 4936 : 섬의 개수
#include <stdio.h>

int queue[2500][2];
int queue_size = 0;
int queue_start = -1;

int w, h;

void findIsland(int m[][50], int visit[][50], int sWidth, int sHeight) {
	if (sWidth > 0) {
		if (visit[sHeight][sWidth - 1] == 0 && m[sHeight][sWidth - 1] == 1) {
			queue[queue_size][0] = sWidth - 1;
			queue[queue_size][1] = sHeight;
			queue_size++;

			visit[sHeight][sWidth - 1] = 1;
		}
		if (sHeight > 0) {
			if (visit[sHeight - 1][sWidth - 1] == 0 && m[sHeight - 1][sWidth - 1] == 1) {
				queue[queue_size][0] = sWidth - 1;
				queue[queue_size][1] = sHeight - 1;
				queue_size++;

				visit[sHeight - 1][sWidth - 1] = 1;
			}
		}
		if (sHeight < h - 1) {
			if (visit[sHeight + 1][sWidth - 1] == 0 && m[sHeight + 1][sWidth - 1] == 1) {
				queue[queue_size][0] = sWidth - 1;
				queue[queue_size][1] = sHeight + 1;
				queue_size++;

				visit[sHeight + 1][sWidth - 1] = 1;
			}
		}
	}
	if (sWidth < w - 1) {
		if (visit[sHeight][sWidth + 1] == 0 && m[sHeight][sWidth + 1] == 1) {
			queue[queue_size][0] = sWidth + 1;
			queue[queue_size][1] = sHeight;
			queue_size++;

			visit[sHeight][sWidth + 1] = 1;
		}
		if (sHeight > 0) {
			if (visit[sHeight - 1][sWidth + 1] == 0 && m[sHeight - 1][sWidth + 1] == 1) {
				queue[queue_size][0] = sWidth + 1;
				queue[queue_size][1] = sHeight - 1;
				queue_size++;

				visit[sHeight - 1][sWidth + 1] = 1;
			}
		}
		if (sHeight < h - 1) {
			if (visit[sHeight + 1][sWidth + 1] == 0 && m[sHeight + 1][sWidth + 1] == 1) {
				queue[queue_size][0] = sWidth + 1;
				queue[queue_size][1] = sHeight + 1;
				queue_size++;

				visit[sHeight + 1][sWidth + 1] = 1;
			}
		}
	}
	if (sHeight > 0) {
		if (visit[sHeight - 1][sWidth] == 0 && m[sHeight - 1][sWidth] == 1) {
			queue[queue_size][0] = sWidth;
			queue[queue_size][1] = sHeight - 1;
			queue_size++;

			visit[sHeight - 1][sWidth] = 1;
		}
	}
	if (sHeight < h - 1) {
		if (visit[sHeight + 1][sWidth] == 0 && m[sHeight + 1][sWidth] == 1) {
			queue[queue_size][0] = sWidth;
			queue[queue_size][1] = sHeight + 1;
			queue_size++;

			visit[sHeight + 1][sWidth] = 1;
		}
	}
	
	queue_start++;
	if (queue_start < queue_size) {
		findIsland(m, visit, queue[queue_start][0], queue[queue_start][1]);
	}
}

int main(void) {
	while (1) {
		int map[50][50];
		int visited[50][50] = { 0, };
		int count = 0;

		queue_size = 0;
		queue_start = 0;

		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1) {

					queue_size = 0;
					queue_start = -1;

					findIsland(map, visited, j, i);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}