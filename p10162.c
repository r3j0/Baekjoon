// 10162 : 전자레인지
#include <stdio.h>

int main(void) {
	int t;
	int a = 0, b = 0, c = 0;
	scanf("%d", &t);
	if (t % 10 != 0) {
		printf("-1");
	}
	else {
		while (t >= 300) {
			a++;
			t -= 300;
		}
		while (t >= 60) {
			b++;
			t -= 60;
		}
		while (t >= 10) {
			c++;
			t -= 10;
		}
		printf("%d %d %d", a, b, c);
	}
	return 0;
}