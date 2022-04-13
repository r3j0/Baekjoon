// 10866. 덱
#include <stdio.h>
#include <string.h>

int deque[20004];

int main(void) {
	int n;
	char command[20];
	int pushint;

	int start_deque = 10002;
	int end_deque = 10002; // start_deque <= [deque] < end_deque

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", command);
		if (!(strcmp(command, "push_front"))) {
			scanf("%d", &pushint);
			start_deque--;
			deque[start_deque] = pushint;
		}
		else if (!(strcmp(command, "push_back"))) {
			scanf("%d", &pushint);
			deque[end_deque] = pushint;
			end_deque++;
		}
		else if (!(strcmp(command, "pop_front"))) {
			if (end_deque - start_deque == 0)
				printf("-1\n");
			else {
				printf("%d\n", deque[start_deque]);
				deque[start_deque] = 0;
				start_deque++;
			}
		}
		else if (!(strcmp(command, "pop_back"))) {
			if (end_deque - start_deque == 0)
				printf("-1\n");
			else {
				printf("%d\n", deque[end_deque-1]);
				deque[end_deque-1] = 0;
				end_deque--;
			}
		}
		else if (!(strcmp(command, "size"))) {
			printf("%d\n", end_deque - start_deque);
		}
		else if (!(strcmp(command, "empty"))) {
			if (end_deque - start_deque == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!(strcmp(command, "front"))) {
			if (end_deque - start_deque == 0)
				printf("-1\n");
			else
				printf("%d\n", deque[start_deque]);
		}
		else if (!(strcmp(command, "back"))) {
			if (end_deque - start_deque == 0)
				printf("-1\n");
			else
				printf("%d\n", deque[end_deque-1]);
		}
	}
	return 0;
}