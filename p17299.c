//17299. 오등큰수
#include <stdio.h>

int arr[1000001] = { 0, };
int stack[1000001] = { 0, };
int stack_size = 0;
int result[1000001];
int cnt[1000001] = { 0, };

int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		result[i] = -1;
		cnt[arr[i]]++;
	}

	for (int i = 0; i < n; i++) {
		while (stack_size > 0) {
			if (cnt[arr[stack[stack_size-1]]] < cnt[arr[i]]) {
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