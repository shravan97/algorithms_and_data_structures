#include <cstdio>

struct node
{
	int data;
	node * left;
	node * right;
};

struct Tree
{
	node * root;
};

void inorder(node * root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data );
		inorder(root->right);
	}
}

node * smallest(node * point)
{
	if(point->left!=NULL)
		return smallest(point->left);
	return point;
}

node * delete_node(node * root,int val)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(val < root->data)
			root->left = delete_node(root->left,val);
		else if(val> root->data)
			root->right = delete_node(root->right,val);
		else
		{
			if(root->left==NULL)
			{
				node * temp = root->right;
				delete root;
				return temp;
			}
			if(root->right==NULL)
			{
				node * temp = root->left;
				delete root;
				return temp; 
			}

			node * minChild = smallest(root->right);
			root->data = minChild->data;
			root->right = delete_node(root->right,minChild->data);
			return root;
		}
		return root;
	}
}

node * Tree_insert(node * root ,int val)
{
	if(root==NULL)
	{
		root = new node;
		root->data = val;
		root->left = NULL;
		root -> right = NULL;
	}
	else
	{
		if(root->data <= val)
			root->right = Tree_insert(root->right , val);
		else
			root->left = Tree_insert(root->left , val);
	}
	return root;
}

int main(int argc, char const *argv[])
{
	Tree t;
	t.root = NULL;
	t.root = Tree_insert(t.root,10);
	t.root = Tree_insert(t.root,5);
	t.root = Tree_insert(t.root,4);
	t.root = Tree_insert(t.root,7);
	t.root = Tree_insert(t.root,6);
	t.root = Tree_insert(t.root,1);
	t.root = Tree_insert(t.root,9);
	t.root = delete_node(t.root,4);
	inorder(t.root);

	return 0;
}