#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void main() {
	BST* bst = (BST*)malloc(sizeof(BST));

	//initBST test
	initBST(bst);
	printTreeInorder(bst);


	//insertBST test

	insertBST(bst, 5);
	insertBST(bst, 2);
	insertBST(bst, 1);
	insertBST(bst, 0);
	insertBST(bst, 3);
	insertBST(bst, 2);
	insertBST(bst, 4);
	insertBST(bst, 6);
	insertBST(bst, 8);
	insertBST(bst, 9);

	printf("\n");
	print_ascii_tree(bst->root);

	//for (int i = 0; i < 12; i++)
	//{
	//	insertBST(bst, i);
	//}

	printTreeInorder(bst);

	//destroyBST test

	//printf("\n");
	//destroyBST(bst);
	//initBST(bst);
	//printTreeInorder(bst);



	//findIndexNFromLast test

	int N = 2;
	printf("\n%d steps from the biggest number there is: %d\n", N, findIndexNFromLast(bst, N));


	//sameHeightLeaves test

	if (sameHeightLeaves(bst) == 1)
	{
		printf("\nAll the leaves are the same height");
	}
	else
	{
		printf("Leaves are not the same height");
	}

	//destroyBST(bst);
}
