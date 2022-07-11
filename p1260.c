// 1260 : DFS와 BFS
#include <stdio.h>

int net[1001][1001] = { 0, };
int dfsVisited[1001] = { 0, };
int bfsVisited[1001] = { 0, };
int queue[1001] = { 0, };
int queue_size = 0;
int queue_start = 0;
void dfs(int nod, int start) {
	//printf("%d번에서 시작. \n", start);
	for (int i = 1; i <= nod; i++) {
		//printf("start : %d / i : %d \n", start, i);
		if (net[start][i] == 1) {
			//printf("%d -> %d 간선 발견 \n", start, i);
			if (dfsVisited[i] == 0) {
				printf("%d ", i);
				dfsVisited[i] = 1;
				dfs(nod, i);
			}
		}
	}
}

void bfs(int nod, int start) {
	for (int i = 1; i <= nod; i++) {
		if (net[start][i] == 1) {
			if (bfsVisited[i] == 0) {
				printf("%d ", i);
				bfsVisited[i] = 1;
				queue[queue_size++] = i;
			}
		}
	}
	if(queue_size > queue_start) {
		bfs(nod, queue[queue_start++]);
	}
}

int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		net[a][b] = 1;
		net[b][a] = 1;
	}
	//DFS
	printf("%d ", v);
	dfsVisited[v] = 1;
	dfs(n, v);
	printf("\n");
	//BFS
	printf("%d ", v);
	bfsVisited[v] = 1;
	bfs(n, v);

	return 0;
}