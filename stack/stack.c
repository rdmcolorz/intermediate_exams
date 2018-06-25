#include <stdlib.h>

struct s_node
{
	void          *content;
	struct s_node *next;
};

struct s_stack 
{
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack	*new;

	if (!(new = malloc(sizeof(struct s_stack))))
		return (NULL);
	new->top = NULL;
	return (new);
}

void	*pop(struct s_stack *stack)
{
	void *temp;

	temp = NULL;
	if (!stack)
		return (NULL);
	if (!stack->top)
		return (NULL);
	temp = stack->top->content;
	stack->top = stack->top->next;
	return (temp);
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node *new;
	struct s_node *temp;

	if (!stack)
		return ;
	new = malloc(sizeof(struct s_node));
	new->content = content;
	if (!stack->top)
	{
		stack->top = new;
		new->next = NULL;
	}
	else
	{
		temp = stack->top;
		stack->top = new;
		new->next = temp;
	}
}

void	*peek(struct s_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->top)
		return (NULL);
	return (stack->top->content);
}

int		isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}
