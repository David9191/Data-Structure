#include "bintree.h"

BinTree	*makeBinTree(BinTreeNode rootNode)
{
	BinTree		*rt_tree;
	BinTreeNode	*root;

	rt_tree = malloc(sizeof(BinTree));
	if (!rt_tree)
		return (NULL);
	root = makeNewNodeBT(rootNode.data);
	if (!root)
		return (NULL);
	rt_tree->pRootNode = root;
	return (rt_tree);
}
BinTreeNode	*getRootNodeBT(BinTree *pBinTree)
{
	BinTreeNode	*rt_root;

	if (!pBinTree)
		return (NULL);
	rt_root = makeNewNodeBT(pBinTree->pRootNode->data);
	if (!rt_root)
		return (NULL);
	return (rt_root);
}
BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*new_left_node;

	if (!pParentNode || pParentNode->pLeftChild)
		return (NULL);
	new_left_node = makeNewNodeBT(element.data);
	pParentNode->pLeftChild = new_left_node;
	return (new_left_node);
}
BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	BinTreeNode	*new_right_node;

	if (!pParentNode || pParentNode->pRightChild)
		return (NULL);
	new_right_node = makeNewNodeBT(element.data);
	pParentNode->pRightChild = new_right_node;
	return (new_right_node);
}
BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
	BinTreeNode	*rt_root;

	if (!pNode)
		return (NULL);
	rt_root = makeNewNodeBT(pNode->pLeftChild->data);
	if (!rt_root)
		return (NULL);
	return (rt_root);
}
BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode)
{
	BinTreeNode	*rt_root;

	if (!pNode)
		return (NULL);
	rt_root = makeNewNodeBT(pNode->pRightChild->data);
	if (!rt_root)
		return (NULL);
	return (rt_root);
}
BinTreeNode	*makeNewNodeBT(TreeNodeData data)
{
	BinTreeNode	*new_node;

	new_node = malloc(sizeof(BinTreeNode));
	if (!new_node)
		return (NULL);
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
		if (pBinTree->pRootNode)
			deleteBinTreeNode(pBinTree->pRootNode);
		return (TRUE);
	}
	return (FALSE);
}
int	deleteBinTreeNode(BinTreeNode *pNode)
{
	if (pNode)
	{
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free (pNode);
		return (TRUE);
	}
	return (FALSE);
}
