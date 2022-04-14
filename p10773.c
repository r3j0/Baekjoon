//10773. 제로
#include <stdio.h>

int money[100000]; 
int money_size = 0;
int allsum = 0;

int main(void) {
	int k;
	int num;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &num);
		if (num == 0) {
			money_size--;
			allsum -= money[money_size];
			money[money_size] = 0;
		}
		else {
			money[money_size] = num;
			allsum += num;
			money_size++;
		}
	}
	printf("%d", allsum);
	return 0;
}