// 10845. 큐
#include <stdio.h>
#include <string.h>

int queue[100001];

int main(void) {
    int n;
    char command[6];
    int push_int;

    int start_queue = 0;
    int end_queue = 0; // start_queue <= [ queue ] < end_queue

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (!(strcmp(command, "push"))) {
            scanf("%d", &push_int);
            queue[end_queue] = push_int;
            end_queue++;
        }
        else if (!(strcmp(command, "pop"))) {
            if (end_queue - start_queue == 0) {
                printf("-1\n");
            }
            else {
                printf("%d\n", queue[start_queue]);
                queue[start_queue] = 0;
                start_queue++;
            }
        }
        else if (!(strcmp(command, "size"))) {
            printf("%d\n", end_queue - start_queue);
        }
        else if (!(strcmp(command, "empty"))) {
            if (end_queue - start_queue == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (!(strcmp(command, "front"))) {
            if (end_queue - start_queue == 0)
                printf("-1\n");
            else
                printf("%d\n", queue[start_queue]);
        }
        else if (!(strcmp(command, "back"))) {
            if (end_queue - start_queue == 0)
                printf("-1\n");
            else
                printf("%d\n", queue[end_queue - 1]);
        }
    }
    return 0;
}