#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
//#define MAX(x, y) (x) > (y) ? (x) : (y)
/*
typedef struct AVLNode {
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
	int count;
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
	node->count = 1;
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
	else if(key == node->key)
	{
		node->count = node->count + 1;
	}

	int balance = get_balance(node);

	//LL 鸥涝 贸府
	if (balance > 1 && key < node->left->key)
	{
		return rotate_right(node);
	}
	//RR 鸥涝 贸府
	if (balance < -1 && key > node->right->key)
	{
		return rotate_left(node);
	}
	//LR 鸥涝 贸府
	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	//RL 鸥涝 贸府
	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

AVLNode* search(AVLNode* node, int key)
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

void inorder(AVLNode* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		//printf("%d ", node->key);
		inorder(node->right);
	}
}

int main(void)
{
	AVLNode* root_of_n = NULL;
	AVLNode* root_of_m = NULL;

	int n, num_of_n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num_of_n);
		root_of_n = insert(root_of_n, num_of_n);
	}
	//inorder(root_of_n);

	int m, num_of_m;
	scanf("%d", &m);
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &num_of_m);
		root_of_m = search(root_of_n, num_of_m);

		if (root_of_m == NULL)
		{
			printf("%d ", 0);
		}
		else
		{
			printf("%d ", root_of_m->count);
		}
	}

	return 0;
}*/

int main(void)
{
	int n, m;

	scanf("%d", &n);
	int* array = (int*)calloc(20000001, sizeof(int));
	int n_num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &n_num);
		array[n_num + 10000000]++;
	}

	scanf("%d", &m);
	int* m_num = (int*)malloc(sizeof(int) * m);
	for (int j = 0; j < m; j++)
	{
		scanf("%d", &m_num[j]);
		printf("%d ", array[m_num[j] + 10000000]);
	}

	return 0;
}