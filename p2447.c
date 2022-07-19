// 2447 : 별 찍기 - 10
#include <stdio.h>

void star(int sero, int garo, int n) {
	if((sero/n) % 3 == 1 && (garo/n) % 3 == 1) {
		printf(" ");
	}
	else {
		if(n / 3 == 0)
			printf("*");
		else 
			star(sero, garo, n/3);
}
}

int main(void) {
	int num;
	scanf("%d",&num);
	
	for(int i = 0; i < num; i++) {
		for(int j = 0; j < num; j++) {
			star(i, j, num);
		}
		printf("\n");
	}
	return 0;
}


