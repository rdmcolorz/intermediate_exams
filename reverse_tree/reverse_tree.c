struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

void	reverse_tree(struct s_node *root)
{
	struct s_node *temp;

	if (!root)
		return ;
	temp = root->right;
	root->right = root->left;
	root->left = temp;
	reverse_tree(root->right);
	reverse_tree(root->left);
}
