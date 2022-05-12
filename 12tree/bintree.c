#include "bintree.h"

BinTree	*makeBinTree(BinTreeNode rootNode)
{
	BinTree		*rt_tree;
	BinTreeNode	*root;

	rt_tree = malloc(sizeof(BinTree));
	if (!rt_tree)
	{
		return (NULL);
	}
	root = getNewNode(rootNode.data);
	if (!root)
	{
		return (NULL);
	}
	rt_tree->pRootNode = root;
	return (rt_tree);
}
BinTreeNode	*getRootNodeBT(BinTree *pBinTree)
{
	BinTreeNode	*rt_root;

	if (!pBinTree)
	{
		return (NULL);
	}
	rt_root = getNewNode(pBinTree->pRootNode->data);
	if (!rt_root)
	{
		return (NULL);
	}
	return (rt_root);
}
BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*new_left_node;

	if (!pParentNode || pParentNode->pLeftChild)
	{
		return (NULL);
	}
	new_left_node = getNewNode(element.data);
	pParentNode->pLeftChild = new_left_node;
	return (new_left_node);
}
BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*new_right_node;

	if (!pParentNode || pParentNode->pRightChild)
	{
		return (NULL);
	}
	new_right_node = getNewNode(element.data);
	pParentNode->pRightChild = new_right_node;
	return (new_right_node);
}
BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
	BinTreeNode	*rt_root;

	if (!pNode)
	{
		return (NULL);
	}
	rt_root = getNewNode(pNode->pLeftChild->data);
	if (!rt_root)
	{
		return (NULL);
	}
	return (rt_root);
}
BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode)
{
	BinTreeNode	*rt_root;

	if (!pNode)
	{
		return (NULL);
	}
	rt_root = getNewNode(pNode->pRightChild->data);
	if (!rt_root)
	{
		return (NULL);
	}
	return (rt_root);
}
BinTreeNode	*getNewNode(TreeNodeData data)
{
	BinTreeNode	*new_node;

	new_node = malloc(sizeof(BinTreeNode));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->data = data;
	new_node->visited = 0;
	new_node->pLeftChild = NULL;
	new_node->pRightChild = NULL;
	return (new_node);
}
// 순회 필요할 듯.
int	deleteBinTree(BinTree *pBinTree)
{
	if (!pBinTree)
	{
		return (FALSE);
	}
	// 순회하면서 deleteBinTreeNode(node);
	return (TRUE);
}
int	deleteBinTreeNode(BinTreeNode *pNode)
{
	if (!pNode)
	{
		return (FALSE);
	}
	free (pNode->pRightChild);
	pNode->pRightChild = NULL;
	free (pNode);
	pNode = NULL;
	return (TRUE);
}
