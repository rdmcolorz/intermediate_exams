#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node **nodes;
};

void	traverse_tree(struct s_node *root, int curr, int *max)
{
	int i = 0;

	if (!root)
		return;
	if (curr > *max)
		*max = curr;
	while (root->nodes[i])
	{
		traverse_tree(root->nodes[i], curr + 1, max);
		i++;
	}
}

int     height_tree(struct s_node *root)
{
    int curr = 0;
    int max = 0;
    traverse_tree(root, curr, &max);
	return (max);
}
/*
#include <stdio.h>
#include <stdlib.h>

struct s_node* b(int v) {
    struct s_node* new = malloc(sizeof(new));
    new->value = v;
    new->nodes = malloc(100000);
    return new;
}

int main() {

    struct s_node* r = b(94);
    r->nodes[0] = b(34);
    r->nodes[1] = b(52);

    r->nodes[0]->nodes[0] = b(1);
    r->nodes[0]->nodes[1] = b(99);
    r->nodes[0]->nodes[2] = b(11);

    r->nodes[0]->nodes[1]->nodes[0] = b(13);

    printf("%d\n", height_tree(r));

    return 0;
}
*/
