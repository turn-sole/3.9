#include"slist.h"
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	//while (cur->next != NULL)
	//while(cur != NULL)
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
		//cur++;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


void SLTPopBack(SLTNode** pphead)
{
	// �������
	assert(pphead);
	assert(*pphead);

	// ����ļ��
	//if (*pphead == NULL)
	//	return;

	// 1��ֻ��һ���ڵ�
	// 2������ڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// ��β
		//SLTNode* prev = NULL;
		//SLTNode* tail = *pphead;
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}

		//free(tail);
		//tail = NULL;

		//prev->next = NULL;

		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	// �������
	assert(pphead);
	assert(*pphead);

	// ����ļ��
	//if (*pphead == NULL)
	//	return;

	SLTNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

// pos֮ǰ����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	assert(pphead);

	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		// �ҵ�pos��ǰһ��λ��
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SLTNode* newnode = BuySLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

// posλ��ɾ��
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	//assert(*pphead);

	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		// �ҵ�pos��ǰһ��λ��
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		//pos = NULL;
	}
}

// pos�������
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// posλ�ú���ɾ��
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	//SLTNode* del = pos->next;
	//pos->next = pos->next->next;
	//free(del);
	//del = NULL;

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}