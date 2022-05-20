#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef	struct BSTDataType
{
	char	ch;
	int		integer;
	float	ft;
}			BSTData;

typedef	struct BinSearchTreeNodeType
{
	int								key;
	BSTData							data;
	struct BinSearchTreeNodeType	*pLeftChild;
	struct BinSearchTreeNodeType	*pRightChild;
}									BSTNode;

typedef	struct BinSearchTreeType
{
	int		currentCount;
	BSTNode	*pRootNode;
}	BinSearchTree;

BinSearchTree	*createBinSearchTree();
int				insertData(BinSearchTree *bst, int key, int data);
int				deleteData(BinSearchTree *bst, int key);
BSTNode			*search(BinSearchTree *bst, int key);
int				deleteBinSearchTree(BinSearchTree *bst);
int				deleteBSTTreeNode(BSTNode *pNode);
void			preorder(BSTNode *root);
void			inorder(BSTNode *root);
void			postorder(BSTNode *root);
BSTNode			*getParentNode(BinSearchTree *bst, int key); // insert private
BSTNode			*createNewNode(int key, int data); // insert private
BSTNode			*searchForDel(BinSearchTree *bst, int key); // deleteData private
int				delZero(BSTNode *parent, BSTNode *del); // deleteData private
int				delOne(BSTNode *parent, BSTNode *del); // deleteData private
int				delTwo(BinSearchTree *bst, BSTNode *parent, BSTNode *del); // deleteData private

#define	TRUE		1
#define	FALSE		0

#endif