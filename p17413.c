//17413. 단어 뒤집기 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100001];
char stack[100001];
char stack_tag[100001];
char result[100001];
int stack_size = 0;
int stack_tag_size = 0;
int result_size = 0;

int main(void) {
	int tagon = 0; // < > 가 활성화 되어있을 시 1

	gets(str);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '<' || tagon == 1) { // <를 발견했거나 < > 안에 있을 시
			tagon = 1;
			
			if (stack_size != 0) {
				for (int i = stack_size - 1; i >= 0; i--) { // 현재 스택에 글자가 남아있다면 전부 역순으로 결과 저장
					result[result_size] = stack[i];
					result_size++;
				}
				stack_size = 0;
			}

			stack_tag[stack_tag_size] = str[i];
			stack_tag_size++;

			if (str[i] == '>') { // > 를 발견했을 시 tagon을 0으로 바꾸어 종료. 입력된 순서대로 결과 저장
				tagon = 0;
				for (int i = 0; i <= stack_tag_size - 1; i++) {
					result[result_size] = stack_tag[i];
					result_size++;
				}
				stack_tag_size = 0;
			}
		}
		else {
			if (str[i] == ' ') {
				if (stack_size != 0) { // 공백 발견 시 역순으로 결과 저장
					for (int i = stack_size - 1; i >= 0; i--) {
						result[result_size] = stack[i];
						result_size++;
					}
					stack_size = 0;
					result[result_size] = ' ';
					result_size++;
				}
			}
			else { // 이 외의 경우 스택에 글자 저장
				stack[stack_size] = str[i];
				stack_size++;
			}
		}
	}

	if (stack_size != 0) { // 끝까지 돌았을 경우 역순으로 결과 저장
		for (int i = stack_size - 1; i >= 0; i--) {
			result[result_size] = stack[i];
			result_size++;
		}
		stack_size = 0;
	}
	
	for (int i = 0; i < result_size; i++)
		printf("%c", result[i]);
	
	return 0;
}