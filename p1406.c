// 1406. 에디터
#include <stdio.h>
#include <string.h>

char string[600000]; // 초기 문자열
char reverse[600000]; /* 커서를 왼쪽 오른쪽으로 이동하거나, 커서 왼쪽 문자 삭제 및 삽입 시 용이하게 하기 위해
reverse 배열을 통해 커서를 왼쪽으로 이동 시 string의 문자를 하나하나씩 reverse로 옮김. ( 오른쪽으로 이동 시 reverse의 문자를 다시 string으로 ) */

int main(void) {
	int inum; // 명령어의 개수
	int string_size; //  string 배열 크기
	int cursor; // 커서 위치. 첫번째(0)이면 맨 왼쪽. 자릿수 + 1번째(자릿수)가 맨 뒤쪽 ( ex. _0_1_2_3_4_ 맨 왼쪽 : 0, 맨 뒤쪽 : 5)
	int count_c; // 자리 바꾸기 위치지점 ( 커서 기준 )

	char ins[5]; // 명령어 입력
	char insert[3]; // 만약 명령이 P일 시 넣는 알파벳

	scanf("%s", string);
	scanf("%d", &inum);

	string_size = strlen(string);
	cursor = string_size; // 커서는 문장 맨 뒤에 위치 

	// abcd 받으면 string_size 는 4
	// _a_b_c_d_ cursor는 0 1 2 3 4 까지 존재 가능.

	for (int i = 0; i < inum; i++) {
		scanf("%s", ins);
		if (ins[0] == 'L') {
			if (cursor != 0) {
				reverse[string_size-cursor] = string[cursor - 1]; // cursor - 1이 커서 왼쪽 문자의 인덱스. reverse 배열의 string 길이에서 커서값을 뺀 만큼의 인덱스에 저장
				// ex. abcde 일시 string_size 는 5. cursor는 5. reverse[0]에 string[4]의 문자가 들어감.
				string[cursor - 1] = '\0'; // NULL로 reverse에 들어간 문자를 string에서 지우기
				cursor--; // 커서 왼쪽으로 이동
			}
		}
		else if (ins[0] == 'D') {
			if (cursor != string_size) {
				string[cursor] = reverse[string_size - cursor - 1]; // cursor이 커서 오른쪽 문자의 인덱스. reverse 배열의 string 길이에서 본래 저장해둔 인덱스에서 불러옴.
				// ex. string : abcd, reverse : e. string_size는 5. cursor는 4. string[4]에 reverse[0]의 문자가 들어감.
				reverse[string_size - cursor - 1] = '\0'; // NULL로 string에 들어간 문자를 reverse에서 지우기
				cursor++; // 커서 오른쪽으로 이동
			}
		}
		else if (ins[0] == 'B') {
			if (cursor != 0 && string_size != 0) { // 커서가 맨 왼쪽이 아니고, string이 비지 않아야함.
				string[cursor - 1] = '\0'; // 커서를 왼쪽으로 옮긴 경우 커서의 오른쪽의 글자는 다 reverse 배열에 들어가므로 한 글자씩 삭제
				cursor--; // 커서 왼쪽으로 이동
				string_size--;
			}
		}
		else if (ins[0] = 'P') {
			scanf("%s", insert);
			if (string[cursor] == '\0') { // 커서가 맨 오른쪽일 경우 자리 만들기
				string[cursor + 1] = '\0';
				string[cursor] = '0';
			}
			string_size++; // 맨 오른쪽이 아닐 경우 string의 오른쪽에 추가
			string[cursor] = insert[0]; 
			cursor++; // 커서 오른쪽으로 이동
		}
	}

	while (cursor < string_size) { // 커서가 문자 길이보다 왼쪽에 있을 때
		string[cursor] = reverse[string_size - cursor - 1]; // reverse 배열에 있는 값 string으로 불러오기
		reverse[string_size - cursor - 1] = '\0';
		cursor++;
	}
	printf("%s", string);
	return 0;
}