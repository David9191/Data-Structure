#ifndef _BIN_TREE_
#define _BIN_TREE_

typedef	struct BinTreeNodeDataType
{
	char	*str;
	int		integer;
	char	ch;
	float	int_float;
}			TreeNodeData;

typedef	struct BinTreeNodeType
{
	TreeNodeData			*data;
	int						visited;
	struct BinTreeNodeType	*pLeftChild;
	struct BinTreeNodeType	*pRightChild;
}							BinTreeNode;

typedef	struct BinTreeType
{
	BinTreeNode	*pRootNode;
}				BinTree;

BinTree		*makeBinTree(BinTreeNode rootNode);
BinTreeNode	*getRootNodeBT(BinTree *pBinTree);
BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element);
BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element);
BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode);
BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode);
int			deleteBinTree(BinTree *pBinTree);
int			deleteBinTreeNode(BinTreeNode *pNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif