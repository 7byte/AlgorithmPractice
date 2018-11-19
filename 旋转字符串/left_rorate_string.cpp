#include <iostream>
#include <memory>

using namespace std;

// 给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，如把字符串
// “abcdef”前面的2个字符‘a’和‘b’移动到字符串的尾部，使得原字符串变成字符
// 串“cdefab”。请写一个函数完成此功能，要求对长度为n的字符串操作的时间复杂度
// 为O（n），空间复杂度为O（1）。
void reverse_string(char *a, unsigned from, unsigned to)
{
	while (from < to)
	{
		a[from] ^= a[to];
		a[to] ^= a[from];
		a[from++] ^= a[to--];
	}
}

void left_rotate_string(char *a, unsigned num, unsigned m)
{
	if (!a)	return;
	m = m % num;
	if (!m) return;
	reverse_string(a, 0, m - 1);
	reverse_string(a, m, num - 1);
	reverse_string(a, 0, num - 1);
}

// 链表翻转。给出一个链表和一个数k，比如，链表为1→2→3→4→5→6，k = 2，则翻
// 转后2→1→6→5→4→3，若k = 3，翻转后3→2→1→6→5→4，若k = 4，翻转后
// 4→3→2→1→6→5，用程序实现
struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode() : val(0), next(NULL)
	{}
};

struct ListNode * reverse_list(struct ListNode *head)
{
	struct ListNode *preNode = head, *nextNode = NULL;
	if (!head) return NULL;
	preNode = head;
	nextNode = head->next;
	preNode->next = NULL;
	while (nextNode)
	{
		head = nextNode;
		nextNode = nextNode->next;
		head->next = preNode;
		preNode = head;
	}
	return head;
}

struct ListNode *rotate_list(struct ListNode *head, int m)
{
	struct ListNode *p = head, *q = NULL;
	if (!head) return NULL;
	while (m-- > 0 && p)
	{
		q = p;
		p = p->next;
	}
	p = reverse_list(p);
	q->next = NULL;
	q = head;
	head = reverse_list(head);
	q->next = p;
	return head;
}

void testPrintList(ListNode *head)
{
	ListNode *p = head;

	cout << "------------" << endl;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}
	cout << "------------" << endl;
}

void destoryList(ListNode *head)
{
	ListNode *p;

	while (head)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

// 单词翻转。输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，
// 句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。例如，输入
// “I am a student.”，则输出“student.a am I”。
void reverse_words(char *a, unsigned num)
{
	int i = 0, left = -1, right = -1;
	for (i = 0; i < (int)num; i++)
	{
		if (a[i] == ' ')
		{
			if (left != -1)
			{
				right = i - 1;
				reverse_string(a, left, right);
				left = right = -1;
			}
		}
		else
		{
			if (left == -1)
			{
				left = i;
			}
		}
	}
	if (left != -1)
	{
		reverse_string(a, left, num - 1);
	}
	reverse_string(a, 0, num - 1);
}

int main()
{
	/*旋转字符串*/
#if 0
	char str[10] = { 0 };
	scanf_s("%s", str, 10);
	left_rotate_string(str, strlen(str), 3);
	printf(str);
#endif

	/*反转链表*/
#if 0
	ListNode *head, *second, *third, *fourth, *fifth;
	head = new ListNode;
	head->val = 1;
	second = new ListNode;
	second->val = 2;
	head->next = second;
	third = new ListNode;
	third->val = 3;
	second->next = third;
	fourth = new ListNode;
	fourth->val = 4;
	third->next = fourth;
	fifth = new ListNode;
	fifth->val = 5;
	fourth->next = fifth;
	testPrintList(head);
	head = rotate_list(head, 1);
	testPrintList(head);
	destoryList(head);
#endif

	/*单词翻转*/
	char str[20] = { 0 };
	strcpy(str, "I am a student.");
	reverse_words(str, strlen(str));
	cout << str << endl;

	return 0;
}
