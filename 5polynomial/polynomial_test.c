#include "polynomial.h"

int	main(void)
{
	Polynomial	*a = createPolynomial();
	Polynomial	*b = createPolynomial();
	Polynomial	*c;

	// a에 오름차순으로 add 하는 작업.
	for (int i = 15; i > 0; i--)
	{
		printf("Add : ");
		addPolyNodeLast(a, i + 1, i + 1);
		displayPolynomial(a);
	}
	printf("\blen : %d\n", getPolynomialLength(a));
	// a를 하나씩 remove 하는 작업.
	// for (int i = 15; i > 0; i--)
	// {
	// 	printf("Del : ");
	// 	displayPolynomial(a);
	// 	removeLLElement(a, i + 1);
	// }
	// printf("\blen : %d\n", getPolynomialLength(a));



	// b에 오름차순으로 add 하는 작업.
	for (int i = 15; i > 0; i--)
	{
		printf("Add : ");
		addPolyNodeLast(b, i + 2, i + 2);
		displayPolynomial(b);
	}
	printf("\blen : %d\n", getPolynomialLength(b));
	// b를 하나씩 remove 하는 작업.
	// for (int i = 15; i > 0; i--)
	// {
	// 	printf("Del : ");
	// 	displayPolynomial(b);
	// 	removeLLElement(b, i + 2);
	// }
	// printf("\blen : %d\n", getPolynomialLength(b));



	c = addPolys(a, b);
	printf("after add : ");
	displayPolynomial(c);
	printf("\blen : %d\n", getPolynomialLength(c));
	// c = subPolys(c, a);
	// printf("after sub : ");
	// displayPolynomial(c);
	// printf("\blen : %d\n", getPolynomialLength(c));
}
