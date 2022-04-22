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
	int tagon = 0;


	gets(str);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '<' || tagon == 1) {
			tagon = 1;
			
			if (stack_size != 0) {
				for (int i = stack_size - 1; i >= 0; i--) {
					result[result_size] = stack[i];
					result_size++;
				}
				stack_size = 0;
			}

			stack_tag[stack_tag_size] = str[i];
			stack_tag_size++;

			if (str[i] == '>') {
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
				if (stack_size != 0) {
					for (int i = stack_size - 1; i >= 0; i--) {
						result[result_size] = stack[i];
						result_size++;
					}
					stack_size = 0;
					result[result_size] = ' ';
					result_size++;
				}
			}
			else {
				stack[stack_size] = str[i];
				stack_size++;
			}
		}
	}

	if (stack_size != 0) {
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