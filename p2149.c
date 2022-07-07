// 2149 : 암호 해독
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char key[12];
	int key_size = 0;
	int keyin[12];
	char str[102];
	int str_size = 0;

	char con[102];

	scanf("%s", key);
	scanf("%s", str);

	key_size = strlen(key);
	str_size = strlen(str);

	
	for (int i = 0; i < key_size; i++) {
		keyin[i] = i;
	}

	/*
	for (int i = 0; i < key_size; i++) {
		printf("%c ", key[i]);
	}
	printf("\n");
	for (int i = 0; i < key_size; i++) {
		printf("%d ", keyin[i]);
	}
	printf("\n");
	*/

	for (int i = 0; i < key_size - 1; i++) {
		for (int j = 0; j < key_size - 1; j++) {
			if (key[j] > key[j+1]) {
				char tmpc = key[j];
				key[j] = key[j+1];
				key[j+1] = tmpc;

				int tmpi = keyin[j];
				keyin[j] = keyin[j+1];
				keyin[j+1] = tmpi;
			}
		}
	}
	/*
	printf("키정렬\n");
	for (int i = 0; i < key_size; i++) {
		printf("%c ", key[i]);
	}
	printf("\n");
	
	for (int i = 0; i < key_size; i++) {
		printf("%d ", keyin[i]);
	}
	printf("\n");
	*/
	int gostr = 0;
	for (int i = 0; i < key_size; i++) {
		int go = keyin[i];
		while (go < str_size) {
			con[go] = str[gostr++];
			go += key_size;
		}
	}
	con[gostr] = '\0';
	printf("%s", con);
	return 0;
}