#include <stdio.h>

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

void	leftbranch(struct s_node *root)
{
	if (!root)
		return ;
	if (root->left || root->right)
		printf(" %i", root->value);
	leftbranch(root->left);
}

void	leaves(struct s_node *root)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
		printf(" %i", root->value);
	leaves(root->right);
	leaves(root->left);
}

void	rightbranch(struct s_node *root)
{
	if (!root)
		return ;
	rightbranch(root->right);
	if (root->left || root->right)
		printf(" %i", root->value);
}

void	perimeter(struct s_node *root)
{
	printf("%i", root->value);
	leftbranch(root->left);
	leaves(root);
	rightbranch(root->right);
	printf("\n");
}
