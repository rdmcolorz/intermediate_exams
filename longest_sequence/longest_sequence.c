struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void    check_long(struct s_node *node, int currlen, int expected, int *max)
{
    if (!node)
        return ;
    if (node->value == expected)
        currlen++;
    else
        currlen = 1;
    if (*max < currlen)
        *max = currlen;
    check_long(node->left, currlen, node->value + 1, max);
    check_long(node->right, currlen, node->value + 1, max);
    return ;
}

int	longest_sequence(struct s_node *node)
{
    if (!node)
        return (0);
    int max = 0;
    int expected = 0;
    int currlen = 0;
    check_long(node, currlen, expected, &max);
    return (max);
}

#include <stdio.h>
#include <stdlib.h>
struct s_node* newNode(int x)
{
    struct s_node* temp = malloc(sizeof(struct s_node));

    temp->value = x;
    temp->left = NULL;
	temp->right = NULL;
    return (temp);
}

int main()
{
    struct s_node* root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(6);
    root->left->right = newNode(9);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(13);
    printf("%i\n", longest_sequence(root));
}