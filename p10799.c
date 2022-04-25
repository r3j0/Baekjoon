//10799. 쇠막대기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[100000];
	int stick_floor[50000] = { 0, };
	int stick_floor_now = -1;
	int stick_floor_high = 0;
	int stick_result = 0;

	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			stick_floor_now++;
			if (stick_floor_now > stick_floor_high)
				stick_floor_high = stick_floor_now;
		}
		else { // ')'
			if (str[i - 1] == '(') {
				for (int i = 1; i <= stick_floor_now; i++) {
					stick_floor[i]++;
				}

			}
			else if (str[i - 1] == ')') {
				stick_floor[stick_floor_now + 1]++;
			}
			stick_floor_now--;
		}
	}
	for (int i = 1; i <= stick_floor_high; i++) {
		stick_result += stick_floor[i];
	}
	printf("%d", stick_result);
	return 0;
}