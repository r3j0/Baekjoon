//10824. 네 수
#include <stdio.h>

int main(void) {
	unsigned long long int a, b, c, d;
	unsigned long long int b_tmp, d_tmp;
	scanf("%llu %llu %llu %llu", &a, &b, &c, &d);
	b_tmp = b;
	d_tmp = d;

	while (b_tmp != 0) {
		a *= 10;
		b_tmp /= 10;
	}
	while (d_tmp != 0) {
		c *= 10;
		d_tmp /= 10;
	}

	printf("%llu", a + b + c + d);
	return 0;

}