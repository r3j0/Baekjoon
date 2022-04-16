//17298. 오큰수
#include <stdio.h>

int arr[1000002];
int stack[1000002];
int stack_size = 0;
int result[1000002];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		result[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		while (stack_size > 0) {
			if (arr[stack[stack_size - 1]] < arr[i])
			{
				result[stack[stack_size - 1]] = arr[i];
				stack_size--;
				stack[stack_size] = -1;
			}
			else
				break;
		}
		stack[stack_size] = i;
		stack_size++;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}

	return 0;
}