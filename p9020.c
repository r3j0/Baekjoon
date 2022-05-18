//9020. 골드바흐의 추측
#include <stdio.h>
#define MAX 10000

int arr[MAX] = { 0, };

void arrChae(void) {
	for (int i = 2; i < MAX; i++) {
		for (int j = 2; j * i < MAX; j++) {
			arr[i * j] = 1;
		}
	}
}

int main(void) {
	int t;
	int num;
	int foc = -1;
	scanf("%d", &t);
	arrChae();
	for (int i = 0; i < t; i++) {
		scanf("%d", &num);
		foc = -1;
		for (int j = 2; j <= num / 2; j++) {
			if (arr[j] == 1)
				continue;
			if (arr[j] == 0 && arr[num - j] == 0) {
				foc = j;
			}
		}
		printf("%d %d\n", foc, num - foc);
	}
	return 0;
}
