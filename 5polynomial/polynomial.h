#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

// malloc \n printf \n memset
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TermType
{
	int			coef;	// Coefficient 계수
	int			degree;
	struct Term	*pLink;
} Term;

typedef struct PolynomialType
{
	int currentElementCount;	// 현재 저장된 항의 개수
	Term headerNode;		// 헤더 노드(Header Node)
} Polynomial;

Polynomial	*createPolynomial();
int			addLLElement(Polynomial* pList, int coef, int degree);
int			removeLLElement(Polynomial* pList, int degree);
void		displayPolynomial(Polynomial* pList);
Term		*getLLElement(Polynomial* pList, int degree);
int			getPolynomialLength(Polynomial* pList);

void		clearPolynomial(Polynomial* pList);
void		deletePolynomial(Polynomial* pList);

#endif

#ifndef	_COMMON_LIST_DEF_
#define	_COMMON_LIST_DEF_

#define	TRUE		1
#define	FALSE		0

#endif
