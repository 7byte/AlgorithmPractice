//����һ���ַ�����������ַ����жԳƵ����ַ�������󳤶ȡ����������ַ���
//��google�������ڸ��ַ�������ĶԳ����ַ����ǡ�goog����������4��
//��ʾ�����ܺܶ��˶�д���ж�һ���ַ����ǲ��ǶԳƵĺ����������Ŀ���Կ����Ǹú����ļ�ǿ�档

#include <stdio.h>

int max_sym_substring(char *s, int num)
{
	int i = 0, max = 0;
	if (!s)
	{
		return 0;
	}
	for (i = 0; i < num; i++)
	{
		int left = i - 1, right = i + 1, len = 1;
		while (left >= 0 && right < num)
		{
			if (s[left--] == s[right++])
			{
				len += 2;
			}
		}
		max = max > len ? max : len;
		left = i, right = i + 1, len = 0;
		while (left >= 0 && right < num)
		{
			if (s[left--] == s[right++])
			{
				len += 2;
			}
		}
		max = max > len ? max : len;
	}
	return max;
}

int main()
{
	char s[] = { "gooogle" };
	printf("%d\n", max_sym_substring(s, strlen(s)));
	return 0;
}