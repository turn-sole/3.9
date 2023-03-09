#include"slist.h"
void TestSList1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
}
void TestSList2()
{
	SLTNode* plist = NULL;
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);
}
void TestSList3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);
}

void TestSList4()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	// 值为2那个节点  *2
	SLTNode* ret = SLTFind(plist, 2);
	ret->data *= 2;
	SLTPrint(plist);
}
void TestSList5()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	// 值为2那个节点  *2
	SLTNode* ret = SLTFind(plist, 2);
	SLTInsert(&plist, ret, 20);
	SLTPrint(plist);
}

void TestSList6()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	// 值为2那个节点  *2
	SLTNode* ret = SLTFind(plist, 2);
	SLTErase(&plist, ret);
	ret = NULL;
	SLTPrint(plist);
}

//int main()
//{
//	TestSList6();
//
//	return 0;
//}


struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	while (cur)
	{
		if (cur->val != val)
		{
			prev = cur;
			cur = cur->next;
		}
		else
		{
			if (prev == NULL)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
	}

	return head;
}


int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	removeElements(n1, 7);

	return 0;
}


//void Func(int y)
//{
//	y = 1;
//}

//void Func(int* p)
//{
//	*p = 1;
//}
//
//int main()
//{
//	int x = 0;
//	Func(&x);
//
//	return 0;
//}

//void Func(int* ptr)
//{
//	ptr = (int*)malloc(sizeof(int));
//}
//
//int main()
//{
//	int* px = NULL;
//	Func(px);
//  free(px);
// 
//
//	return 0;
//}

//void Func(int** pptr)
//{
//	*pptr = (int*)malloc(sizeof(int));
//}
//
//int main()
//{
//	int* px = NULL;
//	Func(&px);
//
//	free(px);
//
//	return 0;
//}

void func(int** y)
{
	*y = (int*)malloc(sizeof(int));
}
int main()
{
	TestSList1();
	int *x = NULL;
	func(&x);
	free(x);
	return 0;
}