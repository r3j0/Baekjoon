//10799. 쇠막대기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[100000];
	int stick_floor[50000] = { 0, };
	int stick_floor_now = -1; // 현재 가리키는 쇠막대기 층
	int stick_floor_high = 0; // 가장 높게 쌓은 쇠막대기 층
	int stick_result = 0;

	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			stick_floor_now++; // 층 증가
			if (stick_floor_now > stick_floor_high)
				stick_floor_high = stick_floor_now;
		}
		else { // ')'
			if (str[i - 1] == '(') { // 레이저
				for (int i = 1; i <= stick_floor_now; i++) {
					stick_floor[i]++; // 층에 있는 모든 쇠막대기 두 동강 냄. 1씩 추가
				}

			}
			else if (str[i - 1] == ')') {
				stick_floor[stick_floor_now + 1]++; // 밑으로 내려감. 레이저 끝 점이랑 안 겹쳐서 하나 더 놓을 수 있으므로 맨 윗층에 하나 더 추가. 
			}
			stick_floor_now--; // 층 내려감.
		}
	}
	for (int i = 1; i <= stick_floor_high; i++) {
		stick_result += stick_floor[i]; // 모든 층 쇠막대기 더하기
	}
	printf("%d", stick_result);
	return 0;
}