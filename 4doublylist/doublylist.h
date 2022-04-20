#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

// malloc
#include <stdlib.h>
// printf
#include <stdio.h>
//memset
#include <string.h>

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;	// 왼쪽 노드
	struct DoublyListNodeType* pRLink;	// 오른쪽 노드
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// 현재 저장된 원소의 개수
	DoublyListNode	headerNode;		// 헤더 노드(Header Node)
} DoublyList;

DoublyList		*createDoublyList();
int				addDLElement(DoublyList* pList, int position, DoublyListNode element);
int				removeDLElement(DoublyList* pList, int position);
void			displayDoublyList(DoublyList* pList);
DoublyListNode*	getDLElement(DoublyList* pList, int position);
int				getDoublyListLength(DoublyList* pList);

void			clearDoublyList(DoublyList* pList);
void			deleteDoublyList(DoublyList* pList);

#endif

#ifndef	_COMMON_LIST_DEF_
#define	_COMMON_LIST_DEF_

#define	TRUE		1
#define	FALSE		0

#endif
