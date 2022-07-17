// 23037 : 5의 수난
#include <stdio.h>

int pow(int n, int su) {
	if (n == 1) return su;
	else return su * pow(n - 1, su);
}

int main(void) {
	int n;
	int sum = 0;
	scanf("%d", &n);
	while (n != 0) {
		sum += pow(5, n % 10);
		n /= 10;
	}
	printf("%d", sum);
	return 0;
}