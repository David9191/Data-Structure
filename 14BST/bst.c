#include "bst.h"

BinSearchTree	*createBinSearchTree()
{
	BinSearchTree	*bst = NULL;

	bst = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (bst)
		bst->pRootNode = NULL;
	return (bst);
}

int	insertData(BinSearchTree *bst, int key, int data)
{
	BSTNode	*parentNode = NULL;
	BSTNode	*newNode = NULL;

	if (bst)
	{
		// 맨 처음 루트 노드
		if (!(bst->pRootNode))
		{
			newNode = createNewNode(key, data);
			bst->pRootNode = newNode;
			bst->currentCount++;
			return (TRUE);
		}
		// 추가할 애의 부모를 찾아줌.
		parentNode = getParentNode(bst, key);
		if (parentNode)
		{
			newNode = createNewNode(key, data);
			if (key < parentNode->key)
				parentNode->pLeftChild = newNode;
			else
				parentNode->pRightChild = newNode;
			bst->currentCount++;
			return (TRUE);
		}
	}
	return (FALSE);
}

BSTNode	*getParentNode(BinSearchTree *bst, int key)
{
	BSTNode	*rtNode = NULL;

	if (bst)
	{
		rtNode = bst->pRootNode;
		while (rtNode)
		{
			if ((key < rtNode->key && !(rtNode->pLeftChild))
				|| (key > rtNode->key && !(rtNode->pRightChild)))
				break ;
			else if (key < rtNode->key)
				rtNode = rtNode->pLeftChild;
			else if (key > rtNode->key)
				rtNode = rtNode->pRightChild;
			else // error : key == rtNode->key;
				return (NULL);
		}
	}
	return (rtNode);
}

BSTNode	*createNewNode(int key, int data)
{
	BSTNode	*newNode = NULL;

	newNode = (BSTNode *)malloc(sizeof(BSTNode));
	if (newNode)
	{
		newNode->key = key;
		newNode->data.integer = data;
		newNode->pLeftChild = NULL;
		newNode->pRightChild = NULL;
	}
	return (newNode);
}

// 자식 노드가 0
// 그냥 걔 삭제하고 부모 가리키는 애 NULL
// 자식 노드가 1 -> 무조건 오른쪽 애가 없음. 왜? 나는 왼쪽 서브트리 중에 제일 큰 애를 찾을 거니까
// 제일 큰 애 == 내 왼쪽 서브트리 중에 가장 오른쪽에 있는 애
// 자식 노드가 2
// 부모랑 왼쪽 자식이랑 바꿈 -> free(leftChild) -> p->pl = NULL;
int	deleteData(BinSearchTree *bst, int key)
{
	BSTNode	*del = NULL;
	BSTNode	*parent = NULL;

	if (bst)
	{
		parent = searchForDel(bst, key);
		if (parent)
		{
			// 삭제 노드 설정
			if (parent == bst->pRootNode) // error 후 수정한 코드. 얘 없으면 에러.
				del = parent; // 이 조건문이 없으면 루트 오른쪽애로 del이 잡힘.
			else if (key == parent->pLeftChild->key)
				del = parent->pLeftChild;
			else
				del = parent->pRightChild;
			// 삭제 노드의 차수에 따른 처리
			if (!(del->pLeftChild) && !(del->pRightChild)) // 차수 0.
				delZero(parent, del);
			else if (del->pLeftChild && del->pRightChild) // 차수 2.
				delTwo(bst, parent, del);
			else // 차수가 1.
				delOne(parent, del);
		}
		bst->currentCount--;
		return (TRUE);
	}
	return (FALSE);
}

BSTNode	*searchForDel(BinSearchTree *bst, int key)
{
	BSTNode	*rtNode = NULL;

	if (bst)
	{
		if (bst->pRootNode->key == key)
			return (bst->pRootNode);
		else
			rtNode = bst->pRootNode;
		while (rtNode)
		{
			if ((key < rtNode->key && key == rtNode->pLeftChild->key)
				|| (key > rtNode->key && key == rtNode->pRightChild->key))
				break ;
			else if (key < rtNode->key)
				rtNode = rtNode->pLeftChild;
			else if (key > rtNode->key)
				rtNode = rtNode->pRightChild;
			else // error : key == rtNode->key;
				return (NULL);
		}
	}
	return (rtNode);
}

int	delZero(BSTNode *parent, BSTNode *del)
{
	if (parent && del)
	{
		if (parent->pLeftChild == del)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
		free (del);
		return (TRUE);
	}
	return (FALSE);
}
int	delOne(BSTNode *parent, BSTNode *del)
{
	BSTNode	*descendant;

	if (parent && del)
	{
		// 후손 선택
		if (del->pLeftChild)
			descendant = del->pLeftChild;
		else
			descendant = del->pRightChild;
		// del위치에 따른 parent 자식 선택
		// del이 parent의 왼쪽에 있었으면 parent->pLeftChild = descendant;
		// del이 parent의 오른쪽에 있었으면 parent->pRightChild = descendant;
		if (parent->pLeftChild == del)
			parent->pLeftChild = descendant;
		else
			parent->pRightChild = descendant;
		free (del);
		return (TRUE);
	}
	return (FALSE);
}
int	delTwo(BinSearchTree *bst, BSTNode *parent, BSTNode *del) // del은 무조건 parent의 RightChild. Why? parent의 LeftChild면 제일 큰 값이 아니니까.
{
	BSTNode	*destParent = NULL;
	BSTNode	*dest = NULL;
	int		checkRoot = 0;

	if (bst && parent && del)
	{
		if (bst->pRootNode == del)
			checkRoot = 1;
		// del의 왼쪽으로 설정
		destParent = del;
		dest = destParent->pLeftChild;
		while (dest->pRightChild) // 왼쪽 서브트리의 가장 고레벨의 맨 오른쪽으로 이동
		{
			destParent = dest;
			dest = dest->pRightChild;
		}
		if (destParent->pLeftChild != dest) // 왼쪽 서브트리의 노드 개수가 1이 아닌 경우.
			destParent->pRightChild = dest->pLeftChild;
		else // 왼쪽 서브트리의 노드 개수가 1인 경우.
			destParent->pLeftChild = NULL;
		dest->pLeftChild = del->pLeftChild;
		dest->pRightChild = del->pRightChild;
		if (parent->pLeftChild == del)
			parent->pLeftChild = dest;
		else
			parent->pRightChild = dest;
		if (checkRoot)
			bst->pRootNode = dest;
		free (del);
		return (TRUE);
	}
	return (FALSE);
}

BSTNode	*search(BinSearchTree *bst, int key)
{
	BSTNode	*rtNode = NULL;

	if (bst)
	{
		rtNode = bst->pRootNode;
		while (rtNode)
		{
			if (key == rtNode->key)
				break ;
			else if (key < rtNode->key)
				rtNode = rtNode->pLeftChild;
			else
				rtNode = rtNode->pRightChild;
		}
	}
	return (rtNode);
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
	if (pNode)
	{
		deleteBSTTreeNode(pNode->pLeftChild);
		deleteBSTTreeNode(pNode->pRightChild);
		free (pNode);
		return (TRUE);
	}
	return (FALSE);
}

void	preorder(BSTNode *root)
{
	if (root && root->data.integer)
	{
		printf("%d ", root->data.integer);
		preorder(root->pLeftChild);
		preorder(root->pRightChild);
	}
}
void	inorder(BSTNode *root)
{
	if (root && root->data.integer)
	{
		inorder(root->pLeftChild);
		printf("%d ", root->data.integer);
		inorder(root->pRightChild);
	}
}
void	postorder(BSTNode *root)
{
	if (root && root->data.integer)
	{
		postorder(root->pLeftChild);
		postorder(root->pRightChild);
		printf("%d ", root->data.integer);
	}
}