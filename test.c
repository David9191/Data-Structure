#include "arraylist.h"

int main(void)
{
	ArrayListNode a, aa, aaa;
	ArrayList b, d, e;
	ArrayList *c;

	c = malloc(sizeof(ArrayList) * 3);
	a.data = 42;
	b.pElement = &a;
	aa.data = 47;
	d.pElement = &aa;
	aaa.data = 52;
	e.pElement = &aaa;
	c[0] = b;
	c[1] = d;
	c[2] = e;
	c->currentElementCount = 3;
	int idx = 0;
	while (idx < (c->currentElementCount) - 1)
	{
		printf("%d | ", c[idx].pElement->data);
		idx++;
	}
	printf("%d", c[idx].pElement->data);
	free(c);
}