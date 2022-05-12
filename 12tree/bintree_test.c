#include "bintree.h"

int	main(void)
{
	BinTreeNode	node;
	node.data.ch = 'A';
	BinTree	*tree = makeBinTree(node);
	printf("data : %c\n", tree->pRootNode->data.ch);
	node.data.ch = 'B';
	insertLeftChildNodeBT(tree->pRootNode, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->data.ch);
	node.data.ch = 'C';
	insertRightChildNodeBT(tree->pRootNode, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->data.ch);
}