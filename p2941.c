//2941. 크로아티아 알파벳
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(void) {
	char str[102];
	int cnt = 0;
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'l' || str[i] == 'n' || str[i] == 's' || str[i] == 'z') {
			if (str[i] == 'c') {
				if (i + 1 != strlen(str)) {
					if (str[i + 1] == '=') {
						cnt++;
						i++;
					}
					else if (str[i + 1] == '-') {
						cnt++;
						i++;
					}
					else {
						cnt++;
					}
				}
				else {
					cnt++;
				}
			}
			else if (str[i] == 'd') {
				if (i + 2 != strlen(str)) {
					if (str[i + 2] == '=' && str[i + 1] == 'z') {
						cnt++;
						i += 2;
					}
					else {
						if (i + 1 != strlen(str)) {
							if (str[i + 1] == '-') {
								cnt++;
								i++;
							}
							else {
								cnt++;
							}
						}
						else {
							cnt++;
						}
					}
				}
				else {
					if (i + 1 != strlen(str)) {
						if (str[i + 1] == '-') {
							cnt++;
							i++;
						}
						else {
							cnt++;
						}
					}
					else {
						cnt++;
					}
				}
			}
			else if (str[i] == 'l') {
				if (i + 1 != strlen(str)) {
					if (str[i + 1] == 'j') {
						cnt++;
						i++;
					}
					else {
						cnt++;
					}
				}
				else {
					cnt++;
				}
			}
			else if (str[i] == 'n') {
				if (i + 1 != strlen(str)) {
					if (str[i + 1] == 'j') {
						cnt++;
						i++;
					}
					else {
						cnt++;
					}
				}
				else {
					cnt++;
				}
			}
			else if (str[i] == 's') {
				if (i + 1 != strlen(str)) {
					if (str[i + 1] == '=') {
						cnt++;
						i++;
					}
					else {
						cnt++;
					}
				}
				else {
					cnt++;
				}
			}
			else if (str[i] == 'z') {
				if (i + 1 != strlen(str)) {
					if (str[i + 1] == '=') {
						cnt++;
						i++;
					}
					else {
						cnt++;
					}
				}
				else {
					cnt++;
				}
			}
		}
		else {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}