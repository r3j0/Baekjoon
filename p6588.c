//6588. 골드바흐의 추측
#include <stdio.h>

int gcd[1000001] = {0,};

int main(void) {
	int n, a;
	int success = 0;
	
	for (int i = 2; i < 1001; i++) {
		for (int p = 2; i * p <= 1000000; p++) {
			gcd[i * p] = -1;
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		
		a = 2;
		success = 1;

		while (a < n / 2 + 1) {
			if (gcd[a] == 0 && gcd[n - a] == 0) {
				success = 0;
				break;
			}
			a++;
		}

		if (success == 0)
			printf("%d = %d + %d\n", n, a, n - a);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}