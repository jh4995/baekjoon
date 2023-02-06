#include <stdio.h>
#include <stdlib.h>

/*
 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ연결리스트ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

int main(void)
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}

	for (int i = 0; i < 5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}*/

////////////////////////////////////////////////////////

/*
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ원형 연결리스트ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL)
		return;
	p = head->link;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}

ListNode* insert_first(ListNode* head, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

int main(void)
{
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	return 0;
}
*/

////////////////////////////////////////////////////////

/*
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ이중 연결리스트ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
typedef struct DListNode {
	int data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, int data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가단계\n");
	for (int i = 0; i < 5; i++)
	{
		dinsert(head, i);
		print_dlist(head);
	}
	printf("삭제단계\n");
	for (int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}

	free(head);
	return 0;
}*/