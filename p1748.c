#include <stdio.h>

int pow(int d) {
	if (d == 1) 
		return 10;
	else 
		return 10 * pow(d - 1);
}

int main(void) {
	int num;
	int sum = 0;
	scanf("%d", &num);

	int i = 1;
	int focus_10 = 1;
	while (1) {
		if (pow(focus_10) > num) {
			sum += (num - i + 1)*(focus_10);
			break;
		}
		else {
			int pre = i;
			i = pow(focus_10);
			sum += ((i - pre) * focus_10);
			focus_10++;
		}
	}
	printf("%d", sum);
	return 0;
}