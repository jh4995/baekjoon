/*
//
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ중위순회 + 전위순회 + 후위순회ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

//중위 순회
void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

//전위 순회
void preorder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//후위 순회
void postorder(TreeNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main(void)
{
	printf("중위 순회=");
	inorder(root);
	printf("\n");

	printf("전위 순회=");
	preorder(root);
	printf("\n");

	printf("후위 순회=");
	postorder(root);
	printf("\n");
	return 0;
}*/

/*
//
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ스레드 이진트리 순회ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode* exp = &n7;

TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
	{
		return q;
	}

	while (q->left != NULL)
	{
		q = q->left;
	}
	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;
	while (q->left)
	{
		q = q->left;
	}
	do {
		printf("%c -> ", q->data);
		q = find_successor(q);
	} while (q);
}

int main(void)
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
	printf("\n");
	return 0;
}*/


/*
//
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ이진 탐색 트리ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (key == node->key)
	{
		return node;
	}
	else if (key < node->key)
	{
		return search(node->left, key);
	}
	else
		return search(node->right, key);
}

TreeNode* new_node(int item)
{
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = item;
	tmp->left = tmp->right = NULL;
	return tmp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL)
	{
		return new_node(key);
	}

	if (key < node->key)
	{
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert_node(node->right, key);
	}

	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->key)
	{
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = delete_node(root->right, key);
	}

	else
	{
		if (root->left == NULL)
		{
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL)
		{
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}
		TreeNode* tmp = min_value_node(root->right);

		root->key = tmp->key;
		root->right = delete_node(root->right, tmp->key);
	}
	return root;
}

void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
	{
		printf("이진 탐색 트리에서 30을 발견함 \n");
	}
	else
	{
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	}
	return 0;
}*/

/*
//
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ히프트리 테스트 프로그램ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;
typedef struct {
	element heap[200];
	int heap_size;
}HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
		{
			child++;
		}
		if (tmp.key >= h->heap[child].key)
		{
			break;
		}

		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = tmp;
	return item;
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}*/

//히프 정렬
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;
typedef struct {
	element heap[200];
	int heap_size;
}HeapType;

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
		{
			child++;
		}
		if (tmp.key >= h->heap[child].key)
		{
			break;
		}

		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = tmp;
	return item;
}

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++)
	{
		insert_max_heap(h, a[i]);
	}
	for (i = n - 1; i >= 0; i--)
	{
		a[i] = delete_max_heap(h);
	}
	free(h);
}

int main(void)
{
	element list[8] = { 23,56,11,9,56,99,27,34 };
	heap_sort(list, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}