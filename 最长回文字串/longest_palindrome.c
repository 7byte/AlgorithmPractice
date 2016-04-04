/*����һ���ַ�����������������Ӵ��ĳ��ȡ�*/

#include <stdio.h>

int LongestPalindrome(const char *s, int n)
{
	int max_len = 0, i = 0;
	if (!s || n < 1)
		return 0;
	for (i = 0; i < n; i++)
	{
		int left = i - 1, right = i + 1, len = 1;
		while (left >= 0 && right < n) //��������ַ����ĳ���������
		{
			if (s[left--] != s[right++])
				break;
			len += 2;
		}
		max_len = max_len > len ? max_len : len;

		left = i, right = i + 1, len = 0;
		while (left >= 0 && right < n) //��������ַ����ĳ�����ż��
		{
			if (s[left--] != s[right++])
				break;
			len += 2;
		}
		max_len = max_len > len ? max_len : len;
	}
	return max_len;
}

int main()
{
	char s[] = "888abcba4888z8884a";
	printf("%d\n", LongestPalindrome(s, (int)strlen(s)));
	return 0;
}
