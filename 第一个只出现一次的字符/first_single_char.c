/*��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ��������� abaccdeff������� b*/

#include <stdio.h>

char first_single_char(char *s, int num)
{
	int i = 0;
	char hashtable[256] = { 0 };

	if (!s)
	{
		return 0;
	}
	for (i = 0; i < num; i++)
	{
		hashtable[s[i]] += 1;
	}
	for (i = 0; i < num; i++)
	{
		if (hashtable[s[i]] == 1)
		{
			return s[i];
		}
	}
	return 0;
}

int main()
{
	char s[] = "abaccdeff";
	printf("%c\n", first_single_char(s, strlen(s)));
	return 0;
}