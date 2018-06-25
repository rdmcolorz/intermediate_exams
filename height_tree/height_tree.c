#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node **nodes;
};

int     height_tree(struct s_node *root)
{
    int i;
    int max;

    max = -1;
    if (!root)
        return max;
    i = 0;
    max = 0;
    while (root->nodes[i])
    {
        if (height_tree(root->nodes[i]) > max)
            max = height_tree(root->nodes[i]);
        i++;
    }
    return (max + 1);
}