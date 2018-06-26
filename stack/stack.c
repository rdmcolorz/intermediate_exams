struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};
#include <stdlib.h>
struct s_stack *init(void)
{
	struct s_stack *new;

	new = malloc(sizeof(struct s_stack));
	new->top = NULL;
	return (new);
}

void *pop(struct s_stack *stack)
{
	void *val;
	struct s_node *temp;

	if (!stack)
		return (NULL);
	temp = stack->top;
	val = temp->content;
	stack->top = stack->top->next;
	free(temp);
	return (val);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new;

	if (!stack || !content)
		return ;		
	new = malloc(sizeof(struct s_node));
	new->content = content;
	if (!stack->top)
	{
		new->next = NULL;
		stack->top = new;
		return ;
	}
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return NULL;
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main()
{
	struct s_stack *new;

	char *a = "hello";
	char *b = "my";
	char *c = "name";
	char *d = "is";
	char *e = "taylor";
	new = init();
	push(new, a);
	push(new, b);
	push(new, c);
	push(new, d);
	push(new, e);
	pop(new);
	pop(new);
	pop(new);
	pop(new);
	pop(new);
	printf("%s\n", peek(new));
	printf("%i\n", isEmpty(new));
	while (new->top)
	{
		printf("%s\n", new->top->content);
		new->top = new->top->next;
	}
}*/
