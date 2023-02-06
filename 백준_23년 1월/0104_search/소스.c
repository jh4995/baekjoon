/*
int list[];

//순차 탐색
int list[];

int seq_search(int key, int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		if (list[i] == key)
		{
			return i;
		}
	}
	return -1;
}

//개선된 순차 탐색
int list[];

int seq_search_2(int key, int low, int high)
{
	int i = 0;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++)
	{
		;
	}
	if (i == (high + 1))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

//이진 탐색(순환 호출)
int list[];

int search_binary(int key, int low, int high)
{
	int middle;

	if (low <= high)
	{
		middle = (low + high) / 2;
		if (key == list[middle])
		{
			return middle;
		}
		else if (key < list[middle])
		{
			return search_binary(key, low, middle - 1);
		}
		else
		{
			return search_binary(key, middle + 1, high);
		}
	}
	return -1;
}

//이진 탐색(반복)
int list[];

int search_binary_2(int key, int low, int high)
{
	int middle;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (key == list[middle])
		{
			return middle;
		}
		else if (key > list[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return -1;
}

//색인 순차 탐색
int list[];

#define INDEX_SIZE 256
typedef struct {
	int key;
	int index;
}itable;
itable index_list[INDEX_SIZE];

int search_index(int key, int n)
{
	int i, low, high;

	if (key<list[0] || key>list[n - 1])
	{
		return -1;
	}

	for (i = 0; i < INDEX_SIZE; i++)
	{
		if (index_list[i].key <= key && index_list[i + 1].key > key)
		{
			break;
		}
	}

	if (i == INDEX_SIZE)
	{
		low = index_list[i - 1].index;
		high = n;
	}
	else
	{
		low = index_list[i - 1].index;
		high = index_list[i + 1].index;
	}

	return seq_search(key, low, high);
}

//보간 탐색
int list[];

int interpol_search(int key, int n)
{
	int low, high, j;

	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low]))
	{
		j = (float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low;
		if (key > list[j])
		{
			low = j + 1;
		}
		else if (key < list[j])
		{
			high = j - 1;
		}
		else
		{
			low = j;
		}
	}
	if (list[low] == key)
	{
		return (low);
	}
	else
	{
		return -1;
	}
}*/

//AVL 트리
#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a)

typedef struct AVLNode {
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
}AVLNode;

int get_height(AVLNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	}
	return height;
}

int get_balance(AVLNode* node)
{
	if (node == NULL)
	{
		return 0;
	}

	return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

AVLNode* rotate_right(AVLNode* parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

AVLNode* rotate_left(AVLNode* parent)
{
	AVLNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}

AVLNode* insert(AVLNode* node, int key)
{
	if (node == NULL)
	{
		return(create_node(key));
	}

	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	else
	{
		return node;
	}

	int balance = get_balance(node);

	//LL 타입 처리
	if (balance > 1 && key < node->left->key)
	{
		return rotate_right(node);
	}
	//RR 타입 처리
	if (balance < -1 && key > node->right->key)
	{
		return rotate_left(node);
	}
	//LR 타입 처리
	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	//RL 타입 처리
	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

void preorder(AVLNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(void)
{
	AVLNode* root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);

	printf("전위 순회 결과 \n");
	preorder(root);

	return 0;
}

//2-3 트리 -> (탐색연산)
/*
Tree23Node* tree23_search(Tree23Node* root, int key)
{
	if (root == NULL)
	{
		return FALSE;
	}
	else if (key == root->data)
	{
		return TRUE;
	}
	else if (root->type == TWO_MODE)
	{
		if (key < root->key)
		{
			return tree23_search(root->left, key);
		}
		else
		{
			return tree23_search(root->right, key);
		}
	}
	else
	{
		if (key < root->key1)
		{
			return tree23_search(root->left, key);
		}
		else if (key > root->key2)
		{
			return tree23_search(root->right, key);
		}
		else
		{
			return tree23_search(root->middle, key);
		}
	}
}*/

//2-3-4 트리