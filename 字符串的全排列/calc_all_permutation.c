// 输入一个字符串，打印出该字符串中字符的所有排列。
// 例如输入字符串abc，则输出由字符a、b、c 所能排列出来的所有字符串
// abc、acb、bac、bca、cab 和 cba。

#include <stdio.h>

void calc_all_permutation(char* s, int from, int to)
{
	if (to <= 1)
	{
		return;
	}

	if (from == to)
	{
		printf("%s\n", s);
	}
	else
	{
		for (int j = from; j <= to; j++)
		{
			char tmp;
			tmp = s[j];
			s[j] = s[from];
			s[from] = tmp;
			calc_all_permutation(s, from + 1, to);
			tmp = s[j];
			s[j] = s[from];
			s[from] = tmp;
		}
	}
}

int main()
{
	char s[] = "abcd";
	calc_all_permutation(s, 0, strlen(s) - 1);
	return 0;
}