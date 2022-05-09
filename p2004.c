//2004. 조합 0의 개수
#include <stdio.h>

long long int output5(long long int n) {
	long long int s5 = 5;
	long long int cnt = 0;
	while (s5 <= n) {
		cnt += n / s5;
		s5 *= 5;
	}
	return cnt;
}

long long int output2(long long int n) {
	long long int s2 = 2;
	long long int cnt = 0;
	while (s2 <= n) {
		cnt += n / s2;
		s2 *= 2;
	}
	return cnt;
}

int main(void) {
	long long int n, m;
	long long int res;
	scanf("%lld %lld", &n, &m);
	long long int a = output5(n);
	long long int b = output2(n);
	long long int c = output5(m);
	long long int d = output2(m);
	long long int e = output5(n - m);
	long long int f = output2(n - m);
	long long int g = a - c - e;
	long long int h = b - d - f;
	if (g > h)
		res = h;
	else
		res = g;

	if (res < 0)
		res = 0;
	
	printf("%lld", res);
	return 0;
}