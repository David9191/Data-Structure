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
	while (idx < curEleCnt)
	{
		printf("%9d | ", pList->pElement[idx].data);
		idx++;
		if (idx % 5 == 0)
			printf("\n");
	}
	printf("\b");
}

int	main(void)
{
	int a = 2147483647, b = 50, c = 55, d = 60, e = 65;
	ArrayListNode aa;
	ArrayListNode bb;
	ArrayListNode cc;
	ArrayListNode dd;
	ArrayListNode ee;
	ArrayListNode ff;
	ArrayListNode gg;
	ArrayListNode hh;
	ArrayListNode ii;
	ArrayListNode jj;

	aa.data = a;
	bb.data = b;
	cc.data = c;
	dd.data = d;
	ee.data = e;
	ff.data = a;
	gg.data = b;
	hh.data = c;
	ii.data = d;
	jj.data = e;

	ArrayList abc;
	abc.currentElementCount = 10;
	abc.maxElementCount = 10;
	abc.pElement = malloc(sizeof(ArrayListNode) * 10);

	abc.pElement[0] = aa;
	abc.pElement[1] = bb;
	abc.pElement[2] = cc;
	abc.pElement[3] = dd;
	abc.pElement[4] = ee;
	abc.pElement[5] = ff;
	abc.pElement[6] = gg;
	abc.pElement[7] = hh;
	abc.pElement[8] = ii;
	abc.pElement[9] = jj;

	// printf("%d | ", abc.pElement[4].data);
	displayArrayList(&abc);
}
