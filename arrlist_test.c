// #include "arraylist.h"

// int main(void)
// {
// 	ArrayListNode a, aa, aaa;
// 	ArrayList b, d, e;
// 	ArrayList *c;

// 	c = malloc(sizeof(ArrayList) * 3);
// 	a.data = 42;
// 	b.pElement = &a;
// 	aa.data = 47;
// 	d.pElement = &aa;
// 	aaa.data = 52;
// 	e.pElement = &aaa;
// 	c[0] = b;
// 	c[1] = d;
// 	c[2] = e;
// 	c->currentElementCount = 3;
// 	int idx = 0;
// 	while (idx < (c->currentElementCount) - 1)
// 	{
// 		printf("%d | ", c[idx].pElement->data);
// 		idx++;
// 	}
// 	printf("%d", c[idx].pElement->data);
// 	free(c);
// }
#include "arraylist.h"

void	displayArrayList(ArrayList *pList)
{
	int	idx;
	int	curEleCnt;

	idx = 0;
	curEleCnt = pList->currentElementCount;
	if (!pList || !curEleCnt)
		return ;
	while (idx < (curEleCnt - 1))
	{
		printf("%d | ", pList->pElement[idx].data);
		idx++;
	}
	printf("%d", pList->pElement[idx].data);
}

int	main(void)
{
	int a = 42, b = 50, c = 55, d = 60;
	ArrayListNode aa;
	ArrayListNode bb;
	ArrayListNode cc;
	ArrayListNode dd;

	aa.data = a;
	bb.data = b;
	cc.data = c;
	dd.data = d;

	ArrayList abc;
	abc.currentElementCount = 4;
	abc.maxElementCount = 4;
	abc.pElement = malloc(sizeof(ArrayListNode) * 4);
	
	abc.pElement[0] = aa;
	abc.pElement[1] = bb;
	abc.pElement[2] = cc;
	abc.pElement[3] = dd;

	displayArrayList(&abc);
}