#include <cstdio>

struct node
{
	int data;
	node * left;
	node * right;
};

struct tree
{
	node * root;
};

int lca(node * root , node * n1 , node * n2)
{
	if(root==NULL)
		return NULL;
	if(root->data > n1 && root->data > n2)
		
}

node * insert(node * root , int val)
{
	if(root==NULL)
	{
		root= new node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if(root->data > val)
		{
			root->left = insert(root->left,val);
		}
		else
			root->right = insert(root->right,val);
	}
	return root;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}