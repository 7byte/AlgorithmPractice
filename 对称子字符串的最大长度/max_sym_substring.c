//输入一个字符串，输出该字符串中对称的子字符串的最大长度。比如输入字符串
//“google”，由于该字符串里最长的对称子字符串是“goog”，因此输出4。
//提示：可能很多人都写过判断一个字符串是不是对称的函数，这个题目可以看成是该函数的加强版。

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