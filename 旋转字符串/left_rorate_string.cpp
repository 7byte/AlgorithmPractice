#include <iostream>

using namespace std;

// ����һ���ַ�����Ҫ����ַ���ǰ������ɸ��ַ��ƶ����ַ�����β��������ַ���
// ��abcdef��ǰ���2���ַ���a���͡�b���ƶ����ַ�����β����ʹ��ԭ�ַ�������ַ�
// ����cdefab������дһ��������ɴ˹��ܣ�Ҫ��Գ���Ϊn���ַ���������ʱ�临�Ӷ�
// ΪO��n�����ռ临�Ӷ�ΪO��1����
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

// ����ת������һ�������һ����k�����磬����Ϊ1��2��3��4��5��6��k = 2����
// ת��2��1��6��5��4��3����k = 3����ת��3��2��1��6��5��4����k = 4����ת��
// 4��3��2��1��6��5���ó���ʵ��
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

// ���ʷ�ת������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䣬
// �����е����Կո��������Ϊ������������ź���ͨ��ĸһ���������磬����
// ��I am a student.�����������student.a am I����
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
	/*��ת�ַ���*/
#if 0
	char str[10] = { 0 };
	scanf_s("%s", str, 10);
	left_rotate_string(str, strlen(str), 3);
	printf(str);
#endif

	/*��ת����*/
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

	/*���ʷ�ת*/
	char str[20] = { 0 };
	strcpy_s(str, "I am a student.");
	reverse_words(str, strlen(str));
	printf(str);

	return 0;
}
