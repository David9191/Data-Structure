#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *res;

	res = malloc(sizeof(LinkedDeque));
	if (res == NULL)
		return (NULL);
	res->currentElementCount = 0;
	res->pFrontNode = NULL;
	res->pRearNode = NULL;
	return (res);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;
	DequeNode *prev;

	if (pDeque == NULL)
		return (FALSE);
	new = malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	if (pDeque->currentElementCount == 0)
	{
		new->pRLink = new;
		new->pLLink = new;
		pDeque->pRearNode = new;
		pDeque->pFrontNode = new;
	}
	else
	{
		prev = pDeque->pFrontNode;
		pDeque->pFrontNode = new;
		prev->pLLink = new;
		new->pRLink = prev;
		new->pLLink = NULL;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;
	DequeNode *prev;

	if (pDeque == NULL)
		return (FALSE);
	new = malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	if (pDeque->currentElementCount == 0)
	{
		new->pRLink = new;
		new->pLLink = new;
		pDeque->pRearNode = new;
		pDeque->pFrontNode = new;
	}
	else
	{
		prev = pDeque->pRearNode;
		pDeque->pRearNode = new;
		prev->pRLink = new;
		new->pLLink = prev;
		new->pRLink = NULL;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*res;

	if (pDeque == NULL || pDeque->currentElementCount == 0)
		return (NULL);
	res = pDeque->pFrontNode;
	pDeque->pFrontNode = res->pRLink;
	if (pDeque->pFrontNode != NULL)
		pDeque->pFrontNode->pLLink = NULL;
	res->pRLink = NULL;
	res->pLLink = NULL;
	pDeque->currentElementCount--;
	return (res);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*res;

	if (pDeque == NULL || pDeque->currentElementCount == 0)
		return (NULL);
	res = pDeque->pRearNode;
	pDeque->pRearNode = res->pLLink;
	if (pDeque->pRearNode != NULL)
		pDeque->pRearNode->pRLink = NULL;
	res->pRLink = NULL;
	res->pLLink = NULL;
	pDeque->currentElementCount--;
	return (res);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL || pDeque->currentElementCount == 0)
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL || pDeque->currentElementCount == 0)
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode* temp;
	DequeNode* temp2;

	if (pDeque == NULL)
		return ;
	if (pDeque->currentElementCount > 0)
	{
		temp = pDeque->pFrontNode;
		while (temp != NULL)
		{
			temp2 = temp;
			temp = temp->pRLink;
			free(temp2);
		}	
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
		return (ERROR);
	return (pDeque->currentElementCount == 0);
}
