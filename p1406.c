// 1406. 에디터
#include <stdio.h>
#include <string.h>

char string[600000];
char reverse[600000];

int main(void) {
	int inum; // 명령어의 개수
	char ins[5]; // 명령어 입력
	int string_size; //  string 크기
	int cursor; // 커서 위치. 0이면 맨 왼쪽. 자릿수 + 1이 맨 뒤쪽
	int count_c; // 자리 바꾸기 위치지점
	char insert[3]; // 넣는 알파벳

	scanf("%s", string);
	scanf("%d", &inum);

	string_size = strlen(string);
	cursor = string_size;

	// abcd 받으면 string_size 는 4
	// _a_b_c_d_ cursor는 0 1 2 3 4 까지 존재 가능.

	for (int i = 0; i < inum; i++) {
		scanf("%s", ins);
		if (ins[0] == 'L') {
			if (cursor != 0) {
				reverse[string_size-cursor] = string[cursor - 1];
				string[cursor - 1] = '\0';
				cursor--;
			}
		}
		else if (ins[0] == 'D') {
			if (cursor != string_size) {
				string[cursor] = reverse[string_size - cursor - 1];
				reverse[string_size - cursor - 1] = '\0';
				cursor++;
			}
		}
		else if (ins[0] == 'B') {
			if (cursor != 0 && string_size != 0) {
				string[cursor - 1] = '\0';
				cursor--;
				string_size--;
			}
		}
		else if (ins[0] = 'P') {
			scanf("%s", insert);
			// 자리 만들기
			if (string[cursor] == '\0') {
				string[cursor + 1] = '\0';
				string[cursor] = '0';
			}
			string_size++;
			string[cursor] = insert[0];
			cursor++;
		}
	}
	while (cursor < string_size) {
		string[cursor] = reverse[string_size - cursor - 1];
		reverse[string_size - cursor - 1] = '\0';
		cursor++;
	}
	printf("%s", string);
	return 0;
}