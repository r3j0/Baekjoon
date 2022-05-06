//2164. 카드2
#include <stdio.h>

int queue[1500001] = {0,};
int queue_start = 0;
int queue_end = 0;
int now = 1;

void _frontPop(void) {
	queue_start++;
	if(queue[queue_start] == 0)
		queue[queue_start] = queue_start+1;
}

void _frontBackpush(void) {
	queue[queue_end] = queue[queue_start];
	queue_start++;
	queue_end++;
}

void _printQueue(void) {
	for (int i = queue_start; i < queue_end; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

int main(void) {
	scanf("%d", &queue_end);
	if (queue_end != 1)
		_frontPop();
	else
		queue[queue_start] = 1;
	while (queue_end > queue_start + 1) {
		_frontBackpush();
		_frontPop();
	}
	printf("%d", queue[queue_start]);
	return 0;
}