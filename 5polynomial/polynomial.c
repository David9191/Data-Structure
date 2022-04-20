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

int	addLLElement(Polynomial* pList, int coef, int degree);

int	removeLLElement(Polynomial* pList, int degree);
void	displayPolynomial(Polynomial* pList);

Term	*getLLElement(Polynomial* pList, int degree)
{
	Term	*node;
	int		idx;

	if (!pList || degree < 0)
		return (NULL);
	node = pList->headerNode.pLink;
	idx = 0;
	while (idx < pList->currentElementCount)
	{
		if (node->degree == degree)
			return (node);
		node = node->pLink;
		idx++;
	}
	return (NULL);
}

int	getPolynomialLength(Polynomial* pList)
{
	if (!pList)
		return ;
	return (pList->currentElementCount);
}

void	clearPolynomial(Polynomial* pList);
void	deletePolynomial(Polynomial* pList);

Polynomial	*sortByExpon(Polynomial *poly);
