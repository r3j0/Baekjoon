// 15965 : K번째 소수
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ch[8000000] = { 0, };

int main(void) {
	int n;
	int cnt = 0;
	for (int i = 2; i < 4000000; i++) {
		if (ch[i] == 0) {
			for (int j = 2; i * j < 8000000; j++) {
				ch[i * j] = 1;
			}
		}
	}
	scanf("%d", &n);
	
	for (int i = 2; i < 8000000; i++) {
		if (ch[i] == 0) {
			cnt++;
			if (cnt == n) {
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}