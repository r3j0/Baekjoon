// 2493 : 탑
#include <stdio.h>

long long int stack[500000][2];
int stack_size = 0;

long long int result[500000] = { 0, };

int main(void) {
	int n;
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (stack_size == 0) {
			stack[stack_size++][0] = tmp;
			stack[stack_size - 1][1] = i;
		}
		else {
			while (stack_size > 0) {
				if (stack[stack_size - 1][0] < tmp) {
					stack_size--;
				}
				else {
					result[i] = stack[stack_size - 1][1]+1;
					break;
				}
			}
			stack[stack_size++][0] = tmp;
			stack[stack_size - 1][1] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%lld ", result[i]);
	}
	return 0;
}