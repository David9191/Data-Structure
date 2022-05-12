#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BinTreeNodeType
{
	char data;
	
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTreeNode* makeNewNodeBT(char data)
{
	BinTreeNode* pReturn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (pReturn != NULL) {
		pReturn->data = data;
		pReturn->pLeftChild = NULL;
		pReturn->pRightChild = NULL;
	}
	return pReturn;
}

BinTree* makeBinTree(char rootNodeData)
{
	BinTree *pReturn = NULL;
	pReturn = (BinTree *)malloc(sizeof(BinTree));
	if (pReturn != NULL) {
		pReturn->pRootNode = makeNewNodeBT(rootNodeData);
		if (pReturn->pRootNode == NULL) {
			free(pReturn);
			pReturn = NULL;
			printf("오류, 메모리 할당(2), makeBinTree()\n");
		}
	}
	else {
		printf("오류, 메모리 할당(1), makeBinTree()\n");
	}
	return pReturn;
}

BinTreeNode* addLeftChildNodeBT(BinTreeNode* pParentNode, char data)
{
	BinTreeNode* pReturn = NULL;
	if (pParentNode != NULL) {
		if (pParentNode->pLeftChild == NULL) {
			pParentNode->pLeftChild = makeNewNodeBT( data );
		}
		else {
			printf("오류, 이미 노드가 존재합니다, addLeftChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode* addRightChildNodeBT(BinTreeNode* pParentNode, char data)
{
	BinTreeNode* pReturn = NULL;
	if (pParentNode != NULL) {
		if (pParentNode->pRightChild == NULL) {
			pParentNode->pRightChild = makeNewNodeBT( data );
		}
		else {
			printf("오류, 이미 노드가 존재합니다, addRightChildNodeBT()\n");
		}
	}
	return pReturn;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	BinTreeNode* pReturn = NULL;
	
	if (pBinTree != NULL) {
		pReturn = pBinTree->pRootNode;
	}
	
	return pReturn;
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode != NULL) {
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree != NULL) {
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL) {
		printf("%c ", pNode->data);
		preorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		preorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
	}
}
void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL) {
		inorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		printf("%c ", pNode->data);
		inorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
	}
}
void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pNode)
{
	if (pNode != NULL) {
		postorderTraversalRecursiveBinTreeNode(pNode->pLeftChild);
		postorderTraversalRecursiveBinTreeNode(pNode->pRightChild);
		printf("%c ", pNode->data);
		
	}
}

int main(void)
{
	BinTreeNode	node;
	node.data = 'A';
	BinTree	*tree = makeBinTree(node.data);
	printf("data : %c\n", tree->pRootNode->data);
	node.data = 'B';
	addLeftChildNodeBT(tree->pRootNode, node.data);
	printf("data : %c\n", tree->pRootNode->pLeftChild->data);
	node.data = 'C';
	addRightChildNodeBT(tree->pRootNode, node.data);
	printf("data : %c\n", tree->pRootNode->pRightChild->data);
	node.data = 'D';
	addLeftChildNodeBT(tree->pRootNode->pLeftChild, node.data);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->data);
	node.data = 'E';
	addRightChildNodeBT(tree->pRootNode->pLeftChild, node.data);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pRightChild->data);
	node.data = 'F';
	addLeftChildNodeBT(tree->pRootNode->pRightChild, node.data);
	printf("data : %c\n", tree->pRootNode->pRightChild->pLeftChild->data);
	node.data = 'G';
	addRightChildNodeBT(tree->pRootNode->pRightChild, node.data);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->data);
	node.data = 'H';
	addLeftChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node.data);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->pLeftChild->data);
	node.data = 'I';
	addRightChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node.data);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pLeftChild->pRightChild->data);
	node.data = 'J';
	addLeftChildNodeBT(tree->pRootNode->pLeftChild->pRightChild, node.data);
	printf("data : %c\n", tree->pRootNode->pLeftChild->pRightChild->pLeftChild->data);
	node.data = 'K';
	addRightChildNodeBT(tree->pRootNode->pRightChild->pLeftChild, node.data);
	printf("data : %c\n", tree->pRootNode->pRightChild->pLeftChild->pRightChild->data);
	node.data = 'L';
	addLeftChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node.data);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->pLeftChild->data);
	node.data = 'M';
	addRightChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node.data);
	printf("data : %c\n", tree->pRootNode->pRightChild->pRightChild->pRightChild->data);

	printf("===================\n");
	printf("preorder 전위\n");
	printf("A B D H I E J C F K G L M\n");
	preorderTraversalRecursiveBinTreeNode(tree->pRootNode);
	printf("\n");
	printf("inorder 중위\n");
	printf("H D I B J E A F K C L G M\n");
	inorderTraversalRecursiveBinTreeNode(tree->pRootNode);
	printf("\n");
	printf("postorder 후위\n");
	printf("H I D J E B K F L M G C A\n");
	postorderTraversalRecursiveBinTreeNode(tree->pRootNode);
	printf("\n");

	printf("===================\n");
	// 여기가 문제
	// deleteBinTreeNode(tree->pRootNode->pLeftChild);
	printf("BDEHIJ removed\n");
	printf("A C F K G L M\n");
	preorderTraversalRecursiveBinTreeNode(tree->pRootNode);
	deleteBinTree(tree);
	preorderTraversalRecursiveBinTreeNode(tree->pRootNode);
	system("leaks bintree_test | grep leaked");
}

