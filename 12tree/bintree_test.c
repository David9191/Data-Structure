#include "bintree.h"

void	preorder(BinTreeNode *root)
{
	if (root)
	{
		printf("%c ", root->data.ch);
		preorder(root->pLeftChild);
		preorder(root->pRightChild);
	}
}

void	inorder(BinTreeNode *root)
{
	if (root)
	{
		inorder(root->pLeftChild);
		printf("%c ", root->data.ch);
		inorder(root->pRightChild);
	}
}

void	postorder(BinTreeNode *root)
{
	if (root)
	{
		postorder(root->pLeftChild);
		postorder(root->pRightChild);
		printf("%c ", root->data.ch);
	}
}

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
	node.data.ch = 'D';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->data.ch);
	node.data.ch = 'E';
	insertRightChildNodeBT(tree->pRootNode->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pRightChild->data.ch);
	node.data.ch = 'F';
	insertLeftChildNodeBT(tree->pRootNode->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pLeftChild->data.ch);
	node.data.ch = 'G';
	insertRightChildNodeBT(tree->pRootNode->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->data.ch);
	node.data.ch = 'H';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->pLeftChild->data.ch);
	node.data.ch = 'I';
	insertRightChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->pRightChild->data.ch);
	node.data.ch = 'J';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pRightChild->pLeftChild->data.ch);
	node.data.ch = 'K';
	insertRightChildNodeBT(tree->pRootNode->pRightChild->pLeftChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pLeftChild->pRightChild->data.ch);
	node.data.ch = 'L';
	insertLeftChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->pLeftChild->data.ch);
	node.data.ch = 'M';
	insertRightChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->pRightChild->data.ch);
	preorder(tree->pRootNode); printf("\n");
	inorder(tree->pRootNode); printf("\n");
	postorder(tree->pRootNode); printf("\n");
}