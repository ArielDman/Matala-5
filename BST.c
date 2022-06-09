#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#define CheckNULL(node) do { \
	 if((node) == NULL){ \
			printf("Memmory allocation failed"); \
			exit(1); \
		} \
	}while(0)

void initBST(BST* bst)
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value)
{
	if (bst->root == NULL)
		bst->root = createNode(value);
	else
		insert(bst->root, createNode(value));
}

TreeNode* createNode(int value)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	CheckNULL(temp);
	temp->left = NULL;
	temp->right = NULL;
	temp->element = value;
	return temp;
}

void insert(TreeNode* root, TreeNode* newNode)
{
	if (newNode->element <= root->element) //left branch
		if (root->left == NULL)
			root->left = newNode;
		else
			insert(root->left, newNode);
	if (newNode->element > root->element) //right branch
		if (root->right == NULL)
			root->right = newNode;
		else
			insert(root->right, newNode);
}

void printTreeInorder(BST* bst)
{
	if (bst->root != NULL) {

		inorder(bst->root);
	}
	else {
		printf("Empty tree");
	}
	printf("\n");
}
void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d,", root->element);
		inorder(root->right);
	}
}

void destroyBST(BST* bst)
{
	if (bst->root != NULL) {
		destroyNode(bst->root);
	}
}

void destroyNode(TreeNode* root)
{
	if (root != NULL) {
		destroyNode(root->right);
		destroyNode(root->left);
		free(root);
	}
}

int findIndexNFromLast(BST* bst, int N)
{
	if (bst->root != NULL) {
		int count = 0;
		int num = 0;
		findNum(bst->root, N, &count, &num);
		return num;
	}
}

void findNum(TreeNode* root, int N, int* count, int* num)
{
	if (root == NULL || *count >= N)
		return;

	findNum(root->right, N, count, num);

	(*count)++;

	if (*count == N) {
		*num = root->element;
		return;
	}

	findNum(root->left, N, count, num);
}

int sameHeightLeaves(BST* bst)
{

	if (bst->root != NULL) {
		int flag = 1;
		int maxlvl = -1;

		isTheSame(bst->root, &flag, 0, &maxlvl);
		return flag;
	}
}

void isTheSame(TreeNode* root, int* flag, int newlvl, int* maxlvl)
{
	if (root == NULL || *flag == 0) return;

	if (root->left == NULL && root->right == NULL) {
		if (*maxlvl == -1) {
			*maxlvl = newlvl;
		}
		else if (*maxlvl != newlvl) {

			*flag = 0;
		}

		return;
	}
	isTheSame(root->right, flag, newlvl + 1, maxlvl);
	isTheSame(root->left, flag, newlvl + 1, maxlvl);
}
