//1157. 단어 공부
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000002];

int lap[26] = { 0, };
int high_value = 0;
int high_index[26] = { 0, };
int high_size = 0;

int main(void) {
	char buf;
	int i = 0;
	while(1) {
		scanf("%c", &buf);
		if (buf == EOF || buf == '\0' || buf == '\n')
			break;
		int tmp = buf >= 97 ? buf - 97 : buf - 65;
		lap[tmp]++;
		if (tmp != high_index) {
			if (lap[tmp] > high_value) {
				high_size = 0;
				high_index[high_size] = tmp;
				high_value = lap[tmp];
				high_size++;
			}
			else if (lap[tmp] == high_value) {
				high_index[high_size] = tmp;
				high_size++;
			}
		}
		i++;
	}
	if (high_size > 1 || high_size < 1)
		printf("?");
	else
		printf("%c", high_index[0]+65);

	return 0;
}