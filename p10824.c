#include <stdio.h>

int main(void) {
	unsigned long long int a, b, c, d;
	unsigned long long int a_tmp, b_tmp, c_tmp, d_tmp;
	scanf("%llu %llu %llu %llu", &a, &b, &c, &d);
	a_tmp = 1;
	b_tmp = b;
	c_tmp = 1;
	d_tmp = d;

	while (b_tmp != 0) {
		a_tmp *= 10;
		b_tmp /= 10;
	}
	while (d_tmp != 0) {
		c_tmp *= 10;
		d_tmp /= 10;
	}

	printf("%llu", ((a_tmp * a) + b + (c_tmp * c) + d));
	return 0;

}