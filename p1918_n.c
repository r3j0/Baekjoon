#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[102];

	char result[102];
	int result_size = 0;

	char _ope[102];
	int _ope_size = 0;

	int pre = 0;
	int brace = 0;

	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		/*
		printf("result : ");
		for (int i = 0; i < result_size; i++)
			printf("%c ", result[i]);
		printf("\n_ope : ");
		for (int i = 0; i < _ope_size; i++)
			printf("%c ", _ope[i]);
		printf("\n");
		*/

		if (str[i] == '+' || str[i] == '-') {
			if (pre == 1 && brace == 0) {
				pre = 0;
				int i = _ope_size - 1;
				for (; i >= 0; i--) {
					if(_ope[i] == '(') {
						_ope_size--;
						break;
					}
					else {
						result[result_size] = _ope[i];
						result_size++;
						_ope_size--;
					}
				}
			}
			_ope[_ope_size] = str[i];
			_ope_size++;
		}
		else if (str[i] == '*' || str[i] == '/') {
			if (pre == 1 && brace == 0) {
				pre = 0;
				int i = _ope_size - 1;
				for (; i >= 0; i--) {
					if(_ope[i] == '(') {
						_ope_size--;
						break;
					}
					else {
						result[result_size] = _ope[i];
						result_size++;
						_ope_size--;
					}
				}
			}
			_ope[_ope_size] = str[i];
			_ope_size++;
			pre = 1;
		}
		else if (str[i] == '(') {
			_ope[_ope_size] = str[i];
			_ope_size++;
			brace++;
		}
		else if (str[i] == ')') {
			brace--;
			int i = _ope_size - 1;
			for (; i >= 0; i--) {
				if (_ope[i] == '(') {
					_ope_size--;
					if (pre == 1) {
						pre = 0;
						continue;
					}
					else {
						break;
					}
				}
				else {
					result[result_size] = _ope[i];
					result_size++;
					_ope_size--;
				}
			}
		}
		else {
			result[result_size] = str[i];
			result_size++;
			if (pre == 0) {
				int i = _ope_size - 1;
				for (; i >= 0; i--) {
					if (_ope[i] == '(') {
						_ope_size--;
						break;
					}
					else {
						result[result_size] = _ope[i];
						result_size++;
						_ope_size--;
					}
				}
			}
		}
	}

	
	for (int i = _ope_size - 1; i >= 0; i--) {
		/*
		printf("result : ");
		for (int i = 0; i < result_size; i++)
			printf("%c ", result[i]);
		printf("\n_ope : ");
		for (int i = 0; i < _ope_size; i++)
			printf("%c ", _ope[i]);
		printf("\n");
		*/

		if (_ope[i] == '(') {
			_ope_size--;
			continue;
		}
		else {
			result[result_size] = _ope[i];
			result_size++;
			_ope_size--;
		}
	}

	for (int i = 0; i < result_size; i++)
		printf("%c", result[i]);
	return 0;
}