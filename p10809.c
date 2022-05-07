//10809. 알파벳 찾기
#include <stdio.h>
#include <string.h>
int main(void)
{
	char ch[100];
	char alpha[26];
	for(int i=0;i<26;i++)
		alpha[i] = -1;
	scanf("%s",ch);
	for(int i=0;i<strlen(ch);i++)
	{ // a 97
		if(alpha[ch[i]-97] == -1)
			alpha[ch[i]-97] = i;
	}
	for(int i=0;i<26;i++)
	{
		printf("%d ",alpha[i]);
	}
	return 0;
}