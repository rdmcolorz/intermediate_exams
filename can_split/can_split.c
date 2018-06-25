
struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int count(struct s_node *root)
{
	if (!root)
		return 0;
	return (count(root->left) + count(root->right) + 1);	
}

int check(struct s_node *root, int count, int *ishalf)
{
	int curr;

	if (!root)
		return (0);
	curr = check(root->left, count, ishalf) + check(root->left, count, ishalf) + 1;
	if (curr == count / 2)
		*ishalf = 1;
	return curr;
}

int can_split(struct s_node *n)
{
	int countnb = count(n);
	int ishalf = 0;

	if (countnb % 2 != 0)
		return (0);
    check(n, countnb, &ishalf);
	return (ishalf);
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
    struct s_node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->right->left = newNode(7);
    root->right->right = newNode(4);

    if (can_split(root))
		printf("YES\n");
	else
		printf("NO\n");
    return 0;
}