#include <stdlib.h>

typedef struct s_node {
    void          *content;
    struct s_node *next;
} Node;

typedef struct s_stack {
    struct s_node *top;
} Stack;

Stack* init(void) {
	Stack* s = malloc(sizeof(Stack));
	s->top = 0;
	return s;
}

void* pop(struct s_stack *stack) {
	if (!stack->top)
		return 0;
	Node* tmp = stack->top;
	void* content = tmp->content;
	stack->top = tmp->next;
	free(tmp);
	return content;
}

void push(struct s_stack *stack, void *content) {
	Node* new = malloc(sizeof(Node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack) {
	if (!stack->top)
		return 0;
	return stack->top->content;
}

int isEmpty(struct s_stack *stack) {
	if (!stack->top)
		return 1;
	return 0;
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
