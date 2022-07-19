// 10026 : 적록색약
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num;
char arr[102][102];
char nc[102][102];
char c[102][102];
int nccount = 0;
int ccount = 0;

void notcolor(int sero, int garo, char focus, int lap) {
	if (nc[sero][garo] == focus) {
		nc[sero][garo] = '0';
		if (lap == 1) {
			nccount += 1;
		}

		if (sero > 0)
			notcolor(sero - 1, garo, focus, lap + 1);
		if (sero < num - 1)
			notcolor(sero + 1, garo, focus, lap + 1);
		if (garo > 0)
			notcolor(sero, garo - 1, focus, lap + 1);
		if (garo < num - 1)
			notcolor(sero, garo + 1, focus, lap + 1);
	}
}
void color(int sero, int garo, char focus, int lap) {
	if (focus == 'R' || focus == 'G') {
		if (c[sero][garo] == 'R' || c[sero][garo] == 'G') {
			c[sero][garo] = '0';
			if (lap == 1) {
				ccount += 1;
			}

			if (sero > 0)
				color(sero - 1, garo, focus, lap + 1);
			if (sero < num - 1)
				color(sero + 1, garo, focus, lap + 1);
			if (garo > 0)
				color(sero, garo - 1, focus, lap + 1);
			if (garo < num - 1)
				color(sero, garo + 1, focus, lap + 1);
		}
	}
	else {
		if (c[sero][garo] == 'B') {
			c[sero][garo] = '0';
			if (lap == 1) {
				ccount += 1;
			}

			if (sero > 0)
				color(sero - 1, garo, focus, lap + 1);
			if (sero < num - 1)
				color(sero + 1, garo, focus, lap + 1);
			if (garo > 0)
				color(sero, garo - 1, focus, lap + 1);
			if (garo < num - 1)
				color(sero, garo + 1, focus, lap + 1);
		}
	}
}

int main(void) {
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", arr[i]);
		strcpy(nc[i], arr[i]);
		strcpy(c[i], arr[i]);
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			notcolor(i, j, arr[i][j], 1);
			color(i, j, arr[i][j], 1);
		}
	}
	printf("%d %d", nccount,ccount);
	return 0;
}