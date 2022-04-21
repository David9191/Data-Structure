#include "polynomial.h"

Polynomial	*createPolynomial()
{
	Polynomial	*rt_poly;

	rt_poly = (Polynomial *)malloc(sizeof(Polynomial));
	if (!rt_poly)
		return (NULL);
	memset(rt_poly, 0, sizeof(Polynomial));
	rt_poly->currentElementCount = 0;
	rt_poly->headerNode.pLink = NULL;
	return (rt_poly);
}

int addPolyNodeLast(Polynomial *pList, float coef, int degree)
{
	Term	*preTerm;
	Term	*addTerm;
	int		idx;
	int		crnt;

	if (!pList || degree < 0 || coef < 1)
		return (FALSE);
	preTerm = &(pList->headerNode);
	crnt = pList->currentElementCount;
	idx = 0;
	while (idx < crnt)
	{
		preTerm = preTerm->pLink;
		idx++;
	}
	addTerm = (Term *)malloc(sizeof(Term));
	// 새로운 텀 설정
	addTerm->coef = coef;
	addTerm->degree = degree;
	// 새로운 텀 pLink, preTerm pLink 설정
	addTerm->pLink = preTerm->pLink;
	preTerm->pLink = addTerm;
	pList->currentElementCount += 1;
	return (TRUE);
}

int	removeLLElement(Polynomial *pList, int degree)
{
	Term	*pre;
	int		idx;
	int		crnt;

	if (!pList || degree < 0)
		return (FALSE);
	pre = &(pList->headerNode);
	crnt = pList->currentElementCount;
	idx = 0;
	while (idx < crnt)
	{
		if ((pre->pLink)->degree == degree)
		{
			pre->pLink = pre->pLink->pLink;
			free (pre->pLink);
			pList->currentElementCount -= 1;
			return (TRUE);
		}
		pre = pre->pLink;
		idx++;
	}
	return (FALSE);
}

void	displayPolynomial(Polynomial *pList)
{
	Term	*node;

	if (!pList || !(pList->headerNode.pLink))
		return ;
	node = pList->headerNode.pLink;
	while (node)
	{
		printf("%dx%d | ", node->coef, node->degree);
		node = node->pLink;
	}
	printf("\b\n");
}

Term	*getLLElement(Polynomial *pList, int degree)
{
	Term	*node;
	int		idx;
	int		crnt;

	if (!pList || degree < 0)
		return (NULL);
	node = pList->headerNode.pLink;
	idx = 0;
	crnt = pList->currentElementCount;
	while (idx < crnt)
	{
		if (node->degree == degree)
			return (node);
		node = node->pLink;
		idx++;
	}
	printf("Don't exist Term of degree you want.");
	return (NULL);
}

int	getPolynomialLength(Polynomial *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

void	clearPolynomial(Polynomial *pList)
{
	Term	*node;

	if (!pList)
		return ;
	node = pList->headerNode.pLink;
	while (node)
	{
		node->coef = 0;
		node->degree = 0;
		node = node->pLink;
	}
}

void	deletePolynomial(Polynomial *pList)
{
	Term	*del;
	Term	*node;

	if (!pList)
		return ;
	clearPolynomial(pList);
	del = (pList->headerNode).pLink;
	while (del)
	{
		node = del->pLink;
		free (del);
		del = node;
	}
	free (pList);
}

Polynomial	*addPolys(Polynomial *aList, Polynomial *bList)
{
	Polynomial	*rtPoly;
	Term		*aTerm;
	Term		*bTerm;

	if (!aList || !bList)
		return (NULL);
	rtPoly = createPolynomial();
	aTerm = (aList->headerNode).pLink;
	bTerm = (bList->headerNode).pLink;
	while (aTerm && bTerm)
	{
		if (aTerm->degree == bTerm->degree)
		{
			addPolyNodeLast(rtPoly, (aTerm->coef + bTerm->coef), aTerm->degree);
			aTerm = aTerm->pLink;
			bTerm = bTerm->pLink;
		}
		else if (aTerm->degree > bTerm->degree)
		{
			addPolyNodeLast(rtPoly, aTerm->coef, aTerm->degree);
			aTerm = aTerm->pLink;
		}
		else
		{
			addPolyNodeLast(rtPoly, bTerm->coef, bTerm->degree);
			bTerm = bTerm->pLink;
		}
	}
	while (aTerm && !bTerm)
	{
		addPolyNodeLast(rtPoly, aTerm->coef, aTerm->degree);
		aTerm = aTerm->pLink;
	}
	while (!aTerm && bTerm)
	{
		addPolyNodeLast(rtPoly, bTerm->coef, bTerm->degree);
		bTerm = bTerm->pLink;
	}
	return (rtPoly);
}

Polynomial	*subPolys(Polynomial *aList, Polynomial *bList)
{
	Polynomial	*rtPoly;
	Term		*aTerm;
	Term		*bTerm;

	if (!aList || !bList)
		return (NULL);
	rtPoly = createPolynomial();
	aTerm = (aList->headerNode).pLink;
	bTerm = (bList->headerNode).pLink;
	while (aTerm && bTerm)
	{
		if (aTerm->degree == bTerm->degree)
		{
			if (aTerm->coef > bTerm->coef)
				addPolyNodeLast(rtPoly, (aTerm->coef - bTerm->coef), aTerm->degree);
			else if (bTerm->coef > aTerm->coef)
				addPolyNodeLast(rtPoly, (bTerm->coef - aTerm->coef), aTerm->degree);
			else
				addPolyNodeLast(rtPoly, 0, aTerm->degree);
			aTerm = aTerm->pLink;
			bTerm = bTerm->pLink;
		}
		else if (aTerm->degree > bTerm->degree)
		{
			if (aTerm->coef > bTerm->coef)
				addPolyNodeLast(rtPoly, (aTerm->coef - bTerm->coef), aTerm->degree);
			else if (bTerm->coef > aTerm->coef)
				addPolyNodeLast(rtPoly, (bTerm->coef - aTerm->coef), aTerm->degree);
			else
				addPolyNodeLast(rtPoly, 0, aTerm->degree);
			addPolyNodeLast(rtPoly, aTerm->coef, aTerm->degree);
			aTerm = aTerm->pLink;
		}
		else
		{
			if (aTerm->coef > bTerm->coef)
				addPolyNodeLast(rtPoly, (aTerm->coef - bTerm->coef), aTerm->degree);
			else if (bTerm->coef > aTerm->coef)
				addPolyNodeLast(rtPoly, (bTerm->coef - aTerm->coef), aTerm->degree);
			else
				addPolyNodeLast(rtPoly, 0, aTerm->degree);
			addPolyNodeLast(rtPoly, bTerm->coef, bTerm->degree);
			bTerm = bTerm->pLink;
		}
	}
	while (aTerm && !bTerm)
	{
		addPolyNodeLast(rtPoly, aTerm->coef, aTerm->degree);
		aTerm = aTerm->pLink;
	}
	while (!aTerm && bTerm)
	{
		addPolyNodeLast(rtPoly, bTerm->coef, bTerm->degree);
		bTerm = bTerm->pLink;
	}
	return (rtPoly);
}
