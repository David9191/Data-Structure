#include "bst.h"

int	main(void)
{
	BinSearchTree	*bst = createBinSearchTree();
	insertData(bst, 30, 30);
	printf("root : %d\n", bst->pRootNode->data.integer);
	insertData(bst, 20, 20);
	insertData(bst, 40, 40);
	insertData(bst, 10, 10);
	insertData(bst, 24, 24);
	insertData(bst, 34, 34);
	insertData(bst, 22, 22);
	insertData(bst, 14, 14);
	insertData(bst, 6, 6);
	insertData(bst, 46, 46);
	insertData(bst, 48, 48);
	insertData(bst, 42, 42);
	insertData(bst, 25, 25);
	insertData(bst, 32, 32);
	insertData(bst, 35, 35);
	preorder(bst->pRootNode);
	printf("\n");
	BSTNode	*searchNode = search(bst, 48);
	printf("48 search : %d\n", searchNode->data.integer);
	deleteData(bst, 30);
	preorder(bst->pRootNode);
	deleteBinSearchTree(bst);
	// system("leaks a.out");
}