//1918. 후위 표기식
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[10102];

char ope[10102];
int ope_size = 0;

char res[10102];
int res_size = 0;

int ope_top(void) {
	return ope[ope_size - 1];
}

int res_top(void) {
	return res[res_size - 1];
}

void ope_push(char ch) {
	ope[ope_size++] = ch;
}

void res_push(char ch) {
	res[res_size++] = ch;
}

int ope_pop(void) {
	ope_size--;
	return ope[ope_size];
}

int res_pop(void) {
	res_size--;
	return res[res_size];
}

int main(void) {
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '+' || str[i] == '-') {
			while (ope_size > 0) {
				if (ope_top() == '(')
					break;
				res_push(ope_pop());
			}
			ope_push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (ope_size > 0) {
				if (ope_top() == '+' || ope_top() == '-' || ope_top() == '(')
					break;
				res_push(ope_pop());
			}
			ope_push(str[i]);
		}
		else if (str[i] == '(') {
			ope_push(str[i]);
		}
		else if (str[i] == ')') {
			while (ope_size > 0) {
				if (ope_top() == '(') {
					ope_pop();
					break;
				}
				res_push(ope_pop());
			}
		}
		else { // operand
			res_push(str[i]);
		}

	}
	
	while (ope_size > 0) {
		if (ope_top() == '(') {
			ope_pop();
			continue;
		}
		res_push(ope_pop());
	}


	for (int i = 0; i < res_size; i++)
		printf("%c", res[i]);
	return 0;

}