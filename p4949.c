//4949. 균형잡힌 세상
#include <stdio.h>
#include <string.h>

char str[1001];
int main(void) {

	int i = 0;
	int result = 0; // -1 : no, 0 : yes;

	while (1) {
		fgets(str,1001,stdin);
		if (str[0] == '.' && strlen(str) == 2)
			break;
		int stack[101]; // 1 : (, 2 : [
		int stack_size = 0;
		result = 0;
		i = 0;
		while(1) {

			if (str[i] == '.')
				break;

			if (str[i] == '(') {
				stack[stack_size] = 1;
				stack_size++;
			}
			else if (str[i] == ')') {
				if (stack_size < 1) {
					result = -1;
					break;
				}
				else {
					if (stack[stack_size - 1] == 1) {
						stack_size--;
					}
					else {
						result = -1;
						break;
					}
				}
			}
			else if (str[i] == '[') {
				stack[stack_size] = 2;
				stack_size++;
			}
			else if (str[i] == ']') {
				if (stack_size < 1) {
					result = -1;
					break;
				}
				else {
					if (stack[stack_size - 1] == 2) {
						stack_size--;
					}
					else {
						result = -1;
						break;
					}
				}
			}

			if (stack_size > 51) {
				result = -1;
				break;
			}
			
			i++;

		}

		if (result == 0 && stack_size == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}