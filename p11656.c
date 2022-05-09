//11656. 접미사 배열
#include <stdio.h>
#include <string.h>

char str[1001];
char buf[1001][1001];
int buf_size = 0;

void jup() {
	for (int p = 0; p < strlen(str); p++) {
		buf_size = 0;
		for (int c = p; c < strlen(str); c++) {
			buf[p][buf_size++] = str[c];
		}
		buf[p][buf_size] = '\0';
	}
}

int main(void) {
	scanf("%s", str);
	jup();
	char go[1001];
	for (int p = 0; p < strlen(str); p++) {
		for (int i = p + 1; i < strlen(str); i++) {
			if (strcmp(buf[p],buf[i])>0) {
				char tmp[1001];
				strcpy(tmp, buf[p]);
				strcpy(buf[p], buf[i]);
				strcpy(buf[i], tmp);
			}
		}
	}
	for (int i = 0; i < strlen(str); i++)
		printf("%s\n", buf[i]);
	return 0;
}