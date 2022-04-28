//1874. 스택 수열
#include <stdio.h>
int stack[100001]; // 스택
int sequence[100000]; // 수열
int operation[100000]; // +, - 연산 수행 순서 저장

int main(void) {
	int n; // n 개의 줄
	int now = 1; // 스택에서 차례대로 넣어야 하는 수.

	int stack_size = 0; // stack 배열의 크기
	int operation_size = 0; // operation_size 배열의 크기

	int no_result = 0; // 값이 1일 시 불가능함을 알림.

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &sequence[i]); // 수열 입력

	for (int i = 0; i < n; i++) {
		if (sequence[i] > now) { // 현재 넣는 정수보다 수열에 할당된 값이 더 클 때 ( ex. now가 1일 때 첫 수열이 5 )
			while (sequence[i] != now) { // 수열 값에 도달할 때까지 now를 stack에 push
				//push
				stack[stack_size] = now;
				now++;
				stack_size++;
				operation[operation_size] = 1; // + 연산
				operation_size += 1;
			}
			operation[operation_size] = 1; // sequence[i] == now 가 되었을 때 push 하고 pop
			operation_size += 1; 
			operation[operation_size] = 2;
			operation_size += 1;
			now++;
			//push and pop
		}
		else if (sequence[i] == now) { // 현재 넣는 정수와 수열에 할당된 값이 같을 때 ( ex. now가 1일 때 첫 수열이 1 )
			operation[operation_size] = 1;
			operation_size += 1;
			operation[operation_size] = 2;
			operation_size += 1;
			now++;
			//push and pop
		}
		else { // sequence[i] < now . 현재 넣는 정수가 수열에 할당된 값보다 클 때 ( ex. now가 5일 때 수열이 2 )
			if (stack_size == 0) // stack에 저장된 값이 하나도 없을 때 : 현재 넣어야할 수는 5인데 다음 수열이 2라 수열에 해당하는 값을 만족시킬 수 없을 때 
				no_result = 1; // NO 출력
			else if (stack[stack_size - 1] == sequence[i]) { // 가장 최근에 넣은 값이 수열에 할당된 값일 때 ( ex. stack에는 1, 2, 3, 4가 저장되어있을 때 수열이 4일 시 )
				operation[operation_size] = 2;
				operation_size += 1; //pop
				stack_size--;
				stack[stack_size] = 0;
			}
			else // stack에 저장된 값은 존재하나, 수열에 할당된 값을 만족시킬 수 없을 때 ( ex. stack에 1, 2, 5 가 저장되어있고 now는 6일 때 수열이 3일 시 )
				no_result = 1;
		}
	}
	if (no_result == 1)
		printf("NO"); // 계산 불가
	else {
		for (int i = 0; i < operation_size; i++) { // 연산 출력
			if (operation[i] == 1)
				printf("+\n");
			else if (operation[i] == 2)
				printf("-\n");
		}
	}
	return 0;
}