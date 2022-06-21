#include <stdio.h>

int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int sero, garo, people;
		int focus_sero, focus_garo;
		scanf("%d %d %d", &sero, &garo, &people);
		people--;
		focus_garo = people / sero + 1;
		focus_sero = people % sero + 1;
		printf("%d%02d\n", focus_sero, focus_garo);
	}
	return 0;
}