// 1439 : 뒤집기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char n[1000002];
int main(void) {
	int cnt = 1;
	char go = '0';
	scanf("%s", n);
	go = n[0];
	for(int i = 1; i < strlen(n); i++) {
		if (go != n[i]) {
			go = (go == '1' ? '0' : '1');
			cnt++;
			//printf("바꿔\n");
		}
	}
	if (cnt == 1)
		printf("0");
	else
		printf("%d", cnt / 2);
	return 0;
}