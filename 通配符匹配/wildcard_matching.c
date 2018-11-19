//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") → false
//isMatch("aa", "aa") → true
//isMatch("aaa", "aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

#include<stdio.h>
#include<memory.h>
#include<stdbool.h>

bool isMatch(char* s, char* p)
{
	const char* star = NULL;
	const char* ss = s;

	while (*s) 
	{
		//advancing both pointers when (both characters match) or ('?' found in pattern)
		//note that *p will not advance beyond its length 
		if ((*p == '?') || (*p == *s)) { s++; p++; continue; }

		// * found in pattern, track index of *, only advancing pattern pointer 
		if (*p == '*') { star = p++; ss = s; continue; }

		//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
		//only advancing pattern pointer
		if (star) { p = star + 1; s = ++ss; continue; }

		//current pattern pointer is not star, last patter pointer was not *
		//characters do not match
		return false;
	}
	//check for remaining characters in pattern
	while (*p == '*') { p++; }

	return !*p;
}

int main()
{
	printf("isMatch('', '') = %s\n", (isMatch("", "") ? "true" : "false"));
	printf("isMatch('', '*') = %s\n", (isMatch("", "*") ? "true" : "false"));
	printf("isMatch('', '?') = %s\n", (isMatch("", "?") ? "true" : "false"));
	printf("isMatch('a', '?*?') = %s\n", (isMatch("a", "?*?") ? "true" : "false"));
	printf("isMatch('aa', 'a') = %s\n", (isMatch("aa", "a") ? "true" : "false"));
	printf("isMatch('aa', 'aa') = %s\n", (isMatch("aa", "aa") ? "true" : "false"));
	printf("isMatch('aaa', 'aa') = %s\n", (isMatch("aaa", "aa") ? "true" : "false"));
	printf("isMatch('aa', '*') = %s\n", (isMatch("aa", "*") ? "true" : "false"));
	printf("isMatch('aa', 'a*') = %s\n", (isMatch("aa", "a*") ? "true" : "false"));
	printf("isMatch('ab', '?*') = %s\n", (isMatch("ab", "?*") ? "true" : "false"));
	printf("isMatch('aab', 'c*a*b') = %s\n", (isMatch("aab", "c*a*b") ? "true" : "false"));
	printf("isMatch('abefcdgiescdfimde', 'ab*cd?i*de') = %s\n", (isMatch("abefcdgiescdfimde", "ab*cd?i*de") ? "true" : "false"));
	return 0;
}