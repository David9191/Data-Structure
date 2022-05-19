#include "bst.h"

BinSearchTree	*createBinSearchTree()
{
	BinSearchTree	*bst = NULL;

	bst = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (bst)
		bst->pRootNode = NULL;
	return (bst);
}

BSTNode	*insertData(BinSearchTree *bst, int key)
{
	BSTNode	*rtNode = NULL;

	if (bst)
	{
		if (!(bst->pRootNode))
		{
			bst->pRootNode = insertDataNode(bst->pRootNode, key);
			rtNode = bst->pRootNode;
		}
		rtNode = insertDataNode(bst->pRootNode, key);
	}
	return (rtNode);
}

// 단순 노드 생성 & 반환 역할만 함. 위치(포인터) 지정은 안해줌.
BSTNode	*insertDataNode(BSTNode *node, int key)
{
	if (!node)
		return (createNewNode(key));
	if (key < node->key)
		node->pLeftChild = insertDataNode(node->pLeftChild, key);
	else if (key > node->key)
		node->pRightChild = insertDataNode(node->pRightChild, key);
	return (node);
}

BSTNode	*createNewNode(int key)
{   
	BSTNode *bst = NULL;

	bst = (BSTNode *)malloc(sizeof(BSTNode));
	if (bst)
	{
		bst->key = key;
		bst->pLeftChild = NULL;
		bst->pRightChild = NULL;
	}
	return (bst);
}

BSTNode *minData(BSTNode *node)
{
	BSTNode *rt = node;

	while (rt->pLeftChild != NULL)
		rt = rt->pLeftChild;
	return (rt);
}

BSTNode	*deleteData(BinSearchTree *bst, int key)
{
	BSTNode	*rtNode = NULL;

	if (bst)
		rtNode = deleteDataNode(bst->pRootNode, key);
	return (rtNode);
}

//변경된 루트 노드 리턴
BSTNode *deleteDataNode(BSTNode *node, int key)
{
	BSTNode *tmp = NULL;

	if (node)
	{
		if (key < node->key)
			node->pLeftChild = deleteDataNode(node->pLeftChild, key);
		else if (key > node->key)
			node->pRightChild = deleteDataNode(node->pRightChild, key);
		else
		{
			// 자식 노드가 없을 때
			if (node->pLeftChild == NULL)
			{
				tmp = node->pRightChild;
				free(node);
				return (tmp);
			}
			// 자식 노드가 하나 있을 때
			else if (node->pRightChild == NULL)
			{
				tmp = node->pLeftChild;
				free(node);
				return (tmp);
			}
			// 자식 노드가 둘 다 있을 때
			tmp = minData(node->pRightChild);// 오른쪽 서브트리에서 제일 작은 값
			node->key = tmp->key;
			node->pRightChild = deleteDataNode(node->pRightChild, tmp->key);
		}
	}
	return (node);
}

BSTNode	*search(BinSearchTree *bst, int key)
{
	BSTNode	*rtNode = NULL;

	if (bst)
		rtNode = searchNode(bst->pRootNode, key);
	return (rtNode);
}

BSTNode	*searchNode(BSTNode *node, int key)
{
	while (node != NULL)
	{
		if (key == node->key)
			return (node);
		else if (key < node->key)
			node = node->pLeftChild;
		else
			node = node->pRightChild;
	}
	return (NULL);
}

int	deleteBinSearchTree(BinSearchTree *bst)
{
	if (!bst)
	{
		if (bst->pRootNode)
			deleteBSTTreeNode(bst->pRootNode);
		return (TRUE);
	}
	return (FALSE);
}

int	deleteBSTTreeNode(BSTNode *pNode)
{
	BSTNode *t_left;
	BSTNode *t_right;

	if (pNode)
	{
		t_left = pNode->pLeftChild;
		t_right = pNode->pRightChild;
		pNode->pLeftChild = NULL;
		pNode->pRightChild = NULL;
		deleteBSTTreeNode(t_left);
		deleteBSTTreeNode(t_right);
		free (pNode);
		return (TRUE);
	}
	return (FALSE);
}

void	preorder(BSTNode *root)
{
	if (root)
	{
		printf("%d ", root->key);
		preorder(root->pLeftChild);
		preorder(root->pRightChild);
	}
}
void	inorder(BSTNode *root)
{
	if (root && root->key)
	{
		inorder(root->pLeftChild);
		printf("%d ", root->key);
		inorder(root->pRightChild);
	}
}
void	postorder(BSTNode *root)
{
	if (root && root->key)
	{
		postorder(root->pLeftChild);
		postorder(root->pRightChild);
		printf("%d ", root->key);
	}
}