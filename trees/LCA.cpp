#include <bits/stdc++.h>
using namespace std;
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

int lca(node * root , int a , int b)
{
	node * curr=root;
	while(1)
	{
		if(curr->data > a && curr->data > b)
			curr = curr->left;
		else if(curr->data < a && curr->data < b)
			curr = curr->right;
		else
			return curr->data;
	}
		
}

node * LCA(node * root,int n1,int n2)
{
	if(root==NULL)
		return NULL;
	
	if(root->data==n1 || root->data==n2)
		return root;
	node * l=LCA(root->left,n1,n2), *r=LCA(root->right,n1,n2);


	if(!l && !r)
		return NULL;
	if(l && r)
		return root;
	if(l)
		return l;
	return r;
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
	tree t;
	t.root=NULL;
	t.root=insert(t.root,7);
	t.root=insert(t.root,9);
	t.root=insert(t.root,5);
	t.root=insert(t.root,6);
	t.root=insert(t.root,8);
	t.root=insert(t.root,4);

	// printf("%d\n",lca(t.root,5,6));
	node * lca = LCA(t.root,4,6);
	cout<<lca->data<<endl; 
	
	return 0;
}