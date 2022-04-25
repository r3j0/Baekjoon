//17299. 오동큰수
#include <stdio.h>

int arr[1000001] = { 0, };
int stack[1000001] = { 0, };
int stack_size = 0;
int result[1000001];
int lap[1000001] = { 0, };

int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		result[i] = -1;
		lap[arr[i]]++;
	}

	for (int i = 0; i < n; i++) {
		while (stack_size > 0) {
			if (lap[arr[stack[stack_size-1]]] < lap[arr[i]]) {
				result[stack[stack_size-1]] = arr[i];
				stack_size--;
			}
			else {
				break;
			}
		}
		stack[stack_size] = i;
		stack_size++;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}