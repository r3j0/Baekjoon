#include <stdio.h>

long long int build[80000] = {0,}; // 0 : height 1 : see buildings
long long int stack[80000];
int stack_size = 0;

int main(void) {
	int n;

	long long int sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &build[i]);
		if (stack_size == 0) {
			stack[stack_size++] = i;
		}
		else {
			while (stack_size > 0) {
				if (build[stack[stack_size - 1]] <= build[i]) {
					stack_size--;
				}
				else {
					break;
				}
			}
			sum += stack_size;
			stack[stack_size++] = i;
		}
	}
	printf("%lld", sum);
	return 0;
}