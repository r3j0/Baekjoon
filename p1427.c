#include <stdio.h>

int main(void) {
	int n;
	int arr[10] = { 0, };
	int arr_size = 0;
	scanf("%d", &n);
	while (n != 0) {
		arr[arr_size++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < arr_size - 1; i++) {
		int tmp = i;
		for (int j = i + 1; j < arr_size; j++) {
			if (arr[tmp] < arr[j]) {
				tmp = j;
			}
		}
		int t = arr[tmp];
		arr[tmp] = arr[i];
		arr[i] = t;
	}
	for (int i = 0; i < arr_size; i++)
		printf("%d", arr[i]);
	return 0;
}