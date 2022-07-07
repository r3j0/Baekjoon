// 1662 : 압축
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[55];
char stack[55];
int stack_size = 0;

long long int floor[55] = { 0, };
int now_floor = 0;

long long int size = 0;

int main(void) {
	scanf("%s", str);
	int plag = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			now_floor++;
			stack[stack_size++] = str[i];
			floor[now_floor]++;
		}
		else if (str[i] == ')') {
			while (stack[stack_size - 1] != '(') {
				floor[now_floor]++;
				stack_size--;
			}
			stack_size--;
			floor[now_floor]--;
			//for (int i = 0; i < stack_size; i++)
				//printf("%c", stack[i]);
			//printf("\n(%d층) %lld만큼 %d번 곱해짐. \n",now_floor,floor[now_floor], stack[stack_size-1] - '0');
			floor[now_floor] *= stack[stack_size-1] - '0';
			stack_size--;
			floor[now_floor - 1] += floor[now_floor];
			floor[now_floor] = 0;
			now_floor--;
		}
		else {
			stack[stack_size++] = str[i];
		}
	}
	while (stack_size > 0) {
		floor[0]++;
		stack_size--;
	}
	printf("%lld", floor[0]);
	return 0;
}