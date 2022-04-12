//1110. 더하기 사이클
#include <stdio.h>

int main(void) {
	int num;
	int first;
	int i = 0;
	scanf("%d", &num);
	first = num;
	do {
		num = ((num%10)*10) + (((num / 10) + (num % 10))%10);
		i++;
	} while (num != first);
	printf("%d", i);
	return 0;
}