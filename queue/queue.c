struct s_node {
		void *content;
		struct s_node *next;
};

struct s_queue {
		struct s_node *first;
		struct s_node *last;
};

#include <stdlib.h>


struct s_queue *init(void)
{
	struct s_queue *new;

	new = malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

struct s_node *newNode(void *content)
{
	struct s_node *new;
	
	new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, void *content)
{
	if (!queue || !content)
		return ;
	if (!queue->last && !queue->first)
	{
		queue->last = newNode(content);
		queue->first = queue->last;
		return ;
	}
	queue->last->next = newNode(content);
	queue->last = queue->last->next;
}

void *dequeue(struct s_queue *queue)
{
	struct s_node *temp;
	void	*val;

	if (!queue || !queue->first || !queue->last) 
		return (NULL);
	temp = queue->first;
	val = temp->content;
	if (queue->first == queue->last)
	{
		queue->first = NULL;
		queue->last = NULL;
 		free(temp);
		if (!val)
			return (NULL);
		return (val);
	}
	queue->first = queue->first->next;
	free(temp);
	if (!val)
		return (NULL);
	return (val);
}

void *peek(struct s_queue *queue)
{
	if (!queue || !queue->first || !queue->last)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue->first || !queue->last)
		return (1);
 	return (0);
}
/*
#include <stdio.h>
int main()
{
	char *a = NULL;
	char *b = "my";
	char *c = "name";
	char *d = "is";
	char *e = "taylor";
	struct s_queue *new;

	new = init();
	enqueue(new, a);
	enqueue(new, b);
	enqueue(new, c);
	enqueue(new, d);
	enqueue(new, e);
	
	printf("this is peeked: %s\n", peek(new));
	printf("is it empty? %i\n", isEmpty(new));
	while (new->first)
	{
		printf("%s\n", new->first->content);
		new->first = new->first->next;
	}
}*/
