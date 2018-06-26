struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node *fast = node;
	struct s_node *slow = node;

	while (node)
	{
		slow = slow->next;
		if (!fast->next)
			return (0);
		if (!fast->next->next)
			return (0);
		fast = fast->next->next;
		if (slow == fast)
			return (1);
		node = node->next;
	}
	return (0);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
	struct s_node *a = malloc(sizeof(struct s_node));
	struct s_node *b = malloc(sizeof(struct s_node));
	struct s_node *c = malloc(sizeof(struct s_node));
	struct s_node *d = malloc(sizeof(struct s_node));
	struct s_node *e = malloc(sizeof(struct s_node));
	struct s_node *f = malloc(sizeof(struct s_node));
	a->value = 1;
	b->value = 2;
	c->value = 3;
	d->value = 4;
	e->value = 5;
	f->value = 6;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = e;
	printf("%i\n", is_looping(a));
}*/
